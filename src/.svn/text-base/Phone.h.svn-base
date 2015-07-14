#ifndef __Phone__
#define	__Phone__

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QSemaphore>
#include <QString>
#include <QQueue>
#include "Account.h"
#include "Network.h"
#include "Message.h"
#include "Call.h"
#include "logging/Logger.h"
#include "voip/SIPStackListener.h"
#include "voip/SIPAccount.h"
#include "voip/SIPCall.h"

/**
 * Software voip phone.
 */
class Phone : public QThread, public micro::voip::SIPStackListener {

        Q_OBJECT

    public :
        /** Enumeration of the phone states. */
        enum PhoneState {
            DESTROYED           = 0,
            CREATED             = 1,
            INITIALIZED         = 2,
            TRANSPORT_CREATED   = 3
        };

        /** Enumeration of the account states. */
        enum AccountState {
            NO_REGISTRATION,
            UNREGISTERED,
            REGISTERED
        };

        /** Enumeration of the online states. */
        enum OnlineState {
            OFFLINE,
            ONLINE
        };

        /** Enumeration of the phone errors. */
        enum Error {
            CREATION_FAILED,
            INITIALIZATION_FAILED,
            TRANSPORT_CREATION_FAILED,
            ACCOUNT_CREATION_FAILED
        };

    private :
        micro::voip::SIPAccount *sipAccount;    /**< SIP account. */
        micro::voip::SIPCall *sipCall;          /**< SIP call. */
        micro::voip::SIPCall *incomingSIPCall;  /**< Incoming SIP call. */
        micro::logging::Logger logger;          /**< Logger. */
        PhoneState state;                       /**< Phone state. */

        QSemaphore semaphore;                   /**< Semaphore for synchronization. */
        QMutex mutex;                           /**< Mutex for synchronization. */
        QQueue<Message> messageQueue;           /**< Message queue. */


        /** Phone initialization. */
        void init();

        /** Phone destroy. */
        void destroy();

        /** Creates the account. */
        void createAccount(const Account &account);

        /** Thread's function. */
        void run();

        QString parseRemoteInfo(const QString &remoteInfo);

    public :
        /** Constructor. */
        Phone();

        /** Destructor. */
        ~Phone();

        /** Processes the change of call state. */
        void onCallState(micro::voip::SIPCall &sipCall, int callState);

        /** Processes the change of registration state. */
        void onRegistrationState(micro::voip::SIPAccount &sipAccount, int registrationCode, int onlineState);

        /** Processes the incoming call. */
        void onIncomingCall(micro::voip::SIPCall &sipCall);

        /** Returns the current phone state. */
        PhoneState getState() const { return state; }

    signals :
        /** Signal called after the phone state has been changed. */
        void phoneStateChanged(int phoneState);

        /** Signal called after the account state has been changed. */
        void accountStateChanged(int accountState);

        /** Signal called after the online state has been changed. */
        void onlineStateChanged(int onlineState);

        /** Signal called after the call state has been changed. */
        void callStateChanged(Call call, int callState);

        /** Signal called after the error occured. */
        void errorOccured(int error);

    public slots :
        /** Changes account settings. */
        void changeAccount(const Account &account);

        /** Changes network settings (STUN, proxy, etc.). */
        void changeNetwork(const Network &network);

        /** Sets account state. */
        //void setAccountState(AccountState state);

        /** Sets online state. */
        void setOnlineState(int state);

        /** Calls the number. */
        void call(const QString &number);

        /** Hangups current call. */
        void hangup();

        /** Answers incoming call. */
        void answer();

        /** Send DTMF digits to remote. */
        void dialDTMF(const QString &digits);

        /** Exits the phone. */
        void exit();

};

#endif	/* __Phone__ */
