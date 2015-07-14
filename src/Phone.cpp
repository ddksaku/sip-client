#include "Phone.h"
#include "voip/SIPStack.h"
#include "voip/SIPCall.h"
#include "voip/SIPCallManager.h"
#include "voip/SIPAccount.h"
#include "voip/SIPAccountManager.h"
#include "voip/SIPTransport.h"
#include "voip/SIPTransportManager.h"
#include "logging/Logger.h"
#include <QtCore/QSettings>
#include <QtCore/QDateTime>
#include <QtCore/QMutexLocker>
#include <QtCore/QRegExp>
#include <QtGui/QMessageBox>


using namespace micro::voip;
using namespace micro::logging;

Phone::Phone() : sipAccount(0), sipCall(0), logger("Phone"), state(DESTROYED), incomingSIPCall(0)
{
}

Phone::~Phone()
{
}

void Phone::onCallState(SIPCall &call, int callState)
{
    static int lastCallId = -1;
    static QDateTime start;
    static QDateTime stop;
    static Call::CallType lastCallType = Call::TYPE_NONE;
    static bool wasConfirmed = false;

    QString number = parseRemoteInfo(call.getRemoteInfo());
    Call::CallType callType = lastCallType;

    switch (callState) {
        case SIPCall::STATE_CALLING :
            logger.debug("state = " + QString::number(callState) + " CALLING");
            start = QDateTime::currentDateTime();
            stop = start;
            lastCallType = Call::TYPE_OUTGOING;
            break;

        case SIPCall::STATE_INCOMING :
            logger.debug("state = " + QString::number(callState) + " INCOMING");
            start = QDateTime::currentDateTime();
            stop = start;
            lastCallType = Call::TYPE_INCOMING;
            break;

        case SIPCall::STATE_CONNECTING :
            logger.debug("state = " + QString::number(callState) + " CONNECTING");
            break;

        case SIPCall::STATE_CONFIRMED :
            logger.debug("state = " + QString::number(callState) + " CONFIRMED");
            wasConfirmed = true;
            start = QDateTime::currentDateTime();
            stop = start;
            break;

        case SIPCall::STATE_DISCONNECTED :
            logger.debug("state = " + QString::number(callState) + " DISCONNECTED");
            stop = QDateTime::currentDateTime();
            if (!wasConfirmed) {
                if (callType == Call::TYPE_INCOMING) {
                    callType = Call::TYPE_MISSED;
                }
            }
            else {
                wasConfirmed = false;
            }
            lastCallType = Call::TYPE_NONE;

            if (sipCall) {
                delete sipCall;
                sipCall = 0;
            }
            break;
    }

    lastCallId = call.getId();

    Call c(number, callType, start, stop);
    emit callStateChanged(c, callState);
}

void Phone::onRegistrationState(SIPAccount &sipAccount, int registrationCode, int onlineState)
{
    logger.debug("regCode = " + QString::number(registrationCode) + ", online = " + QString::number(onlineState));

    switch (registrationCode) {
        case 200 :  // 200 = OK
            emit accountStateChanged(REGISTERED);
            break;

        case 503 :
            emit accountStateChanged(UNREGISTERED);
            break;

        default :
            emit accountStateChanged(UNREGISTERED);
            break;
    }

}

void Phone::onIncomingCall(SIPCall &call)
{
    if (sipCall) {
        delete sipCall;
    }

    sipCall = new SIPCall(call.getId());
}

void Phone::setOnlineState(int state)
{
    if (sipAccount) {
        QMutexLocker locker(&mutex);
        switch (state) {
            case ONLINE :
                messageQueue.enqueue(Message(Message::ONLINE));
                semaphore.release();
                break;
            case OFFLINE :
                messageQueue.enqueue(Message(Message::OFFLINE));
                semaphore.release();
                break;
        }
    }
}

void Phone::changeAccount(const Account &account)
{
    QStringList list;
    list << account.getTitle() << account.getUsername() << account.getPassword() << account.getRegistrar();
    QMutexLocker locker(&mutex);
    messageQueue.enqueue(Message(Message::CHANGE_ACCOUNT, list));
    semaphore.release();
}

void Phone::changeNetwork(const Network &network)
{
    QMutexLocker locker(&mutex);
    messageQueue.enqueue(Message(Message::CHANGE_NETWORK));
    semaphore.release();
}

void Phone::call(const QString &number)
{
    QStringList list;
    list << number;
    QMutexLocker locker(&mutex);
    messageQueue.enqueue(Message(Message::CALL, list));
    semaphore.release();
}

void Phone::hangup()
{
    QMutexLocker locker(&mutex);
    messageQueue.enqueue(Message(Message::HANGUP));
    semaphore.release();
}

void Phone::answer()
{
    QMutexLocker locker(&mutex);
    messageQueue.enqueue(Message(Message::ANSWER));
    semaphore.release();
}

void Phone::dialDTMF(const QString &digits)
{
    QStringList list;
    list << digits;
    QMutexLocker locker(&mutex);
    messageQueue.enqueue(Message(Message::DIAL_DTMF, list));
    semaphore.release();
}

void Phone::exit()
{
    QMutexLocker locker(&mutex);
    messageQueue.enqueue(Message(Message::EXIT));
    semaphore.release();
}

QString Phone::parseRemoteInfo(const QString &remoteInfo)
{
    QRegExp regExp("<(.*)>");
    int position = regExp.indexIn(remoteInfo);
    if (position != -1) {
        return regExp.cap(1);
    }
    else {
        return remoteInfo;
    }
}

void Phone::init()
{
    QSettings settings;

    if (state < CREATED) {
        // SIP Stack creation
        if (SIPStack::create() == false) {
            logger.error("SIP Stack creation failed.");
            emit errorOccured(CREATION_FAILED);
            return;
        }

        state = CREATED;
    }

    if (state < INITIALIZED) {
        // SIP Stack initialization
        SIPConfig config;
        config.setUserAgent("Chatty v1.0");
        if (settings.value("settings/stun/use", QVariant(false)).toBool()) {
            config.setSTUNServer(settings.value("settings/stun/server").toString());
        }

        if (settings.value("settings/proxy/use", QVariant(false)).toBool()) {
            config.setProxyServer(settings.value("settings/proxy/proxy").toString());
            config.setProxyPort(settings.value("settings/proxy/port").toString());
        }

        config.setLogFile("./logs/pjsip.log");

        SIPStack::setListener(this);

        if (SIPStack::init(config) == false) {
            logger.error("SIP Stack initialization failed.");
            emit errorOccured(INITIALIZATION_FAILED);
            return;
        }
        state = INITIALIZED;
        emit phoneStateChanged(state);
    }

    if (state < TRANSPORT_CREATED) {
        // transport initialization
        logger.debug("creating UDP transport");
        SIPTransport *transport = SIPTransportManager::createTransport(SIPTransport::TRANSPORT_UDP, 5060);
        if (transport == 0) {
            logger.error("Creating transport failed");
            emit errorOccured(TRANSPORT_CREATION_FAILED);
            return;
        }

        state = TRANSPORT_CREATED;
        emit phoneStateChanged(TRANSPORT_CREATED);
    }

    // account initialization

    QString title = settings.value("accounts/default/title").toString();
    QString username = settings.value("accounts/default/username").toString();
    QString password = settings.value("accounts/default/password").toString();
    QString registrar = settings.value("accounts/default/registrar").toString();

    Account account(title, username, password, registrar);
    if (username.isEmpty() || password.isEmpty() || registrar.isEmpty()) {
        logger.debug("Account data not filled. Skip creating account.");
        return;
    }
    createAccount(account);

    /*pjmedia_snd_dev_info info[3];
    unsigned int count = 3;
    if (pjsua_enum_snd_devs(info, &count) == PJ_SUCCESS) {
        for (int i = 0; i < count; i++) {
            logger.debug(info[i].name);
            QString number;
            number.setNum(info[i].default_samples_per_sec);
            logger.debug(number.toStdString());
        }
    }*/
}

void Phone::destroy()
{
    SIPStack::destroy();
    state = DESTROYED;
    emit phoneStateChanged(state);
}

void Phone::createAccount(const Account &account)
{
    if (sipAccount) {
        SIPAccountManager::removeAccount(sipAccount);
        delete sipAccount;
    }

    logger.debug("Creating account : " + account.getTitle() + ", " + account.getUsername() + ", " + account.getRegistrar());

    sipAccount = SIPAccountManager::addAccount(account.getTitle(), account.getUsername(), account.getPassword(), account.getRegistrar(), true);
    if (sipAccount == 0) {
        logger.error("Creating account failed");
        emit errorOccured(ACCOUNT_CREATION_FAILED);
        return;
    }

    if (!sipAccount->hasRegistration()) {
        emit accountStateChanged(NO_REGISTRATION);
    }
}

void Phone::run()
{
    init();

    forever {
        semaphore.acquire();

        mutex.lock();
        Message message = messageQueue.dequeue();
        mutex.unlock();

        QStringList parameters = message.getParameters();

        switch (message.getCode()) {
            case Message::CALL :
                if (!sipCall) {
                    logger.debug("Call " + parameters[0]);
                    sipCall = SIPCallManager::makeCall(sipAccount, parameters[0]);
                    if (!sipCall) {
                        Call call(parameters[0], Call::TYPE_NONE);
                        emit callStateChanged(call, (int)SIPCall::STATE_DISCONNECTED);
                    }
                }
                break;

            case Message::HANGUP :
                if (sipCall) {
                    if (sipCall->hangup()) {
                        delete sipCall;
                        sipCall = 0;
                    }
                }
                break;

            case Message::ANSWER :
                if (sipCall) {
                    sipCall->answer();
                }
                break;

            case Message::DIAL_DTMF :
                if (sipCall) {
                    sipCall->dialDTMF(parameters[0]);
                }
                break;

            case Message::CHANGE_ACCOUNT :
                if (state > INITIALIZED) {
                    createAccount(Account(parameters[0], parameters[1], parameters[2], parameters[3]));
                }
                break;

            case Message::CHANGE_NETWORK :
                //if (state > INITIALIZED) {
                //    destroy();
                //}
                //init();
                break;

            case Message::ONLINE :
                if (sipAccount->setOnline(true)) {
                    logger.debug("ONLINE : " + sipAccount->getOnlineText());
                    emit onlineStateChanged(ONLINE);
                }
                break;

            case Message::OFFLINE :
                if (sipAccount->setOnline(false)) {
                    logger.debug("OFFLINE : " + sipAccount->getOnlineText());
                    emit onlineStateChanged(OFFLINE);
                }
                break;

            case Message::EXIT :
                destroy();
                return;

            default :
                break;
        }
    }
}
