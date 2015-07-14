#include "DialPad.h"
#include "Phone.h"
#include "voip/SIPCall.h"
#include <QtGui/QWidget>
#include <QtGui/QMenu>
#include <QtGui/QCompleter>
#include <QtGui/QMessageBox>
#include <QtGui/QPalette>

using namespace micro::voip;


DialPad::DialPad(QWidget *parent) : QDialog(parent), callState(SIPCall::STATE_NULL)
{
    setupUi(this);

    QMenu *menu = new QMenu(this);
    menu->addAction(onlineAction);
    menu->addAction(offlineAction);

    statusButton->setMenu(menu);

    blinkTimer.setInterval(750);
    connect(&blinkTimer, SIGNAL(timeout()), this, SLOT(onBlinkTimeout()));

    completer = new QCompleter(this);
    dialLineEdit->setCompleter(completer);
}

void DialPad::onCallStateChanged(Call call, int callState)
{

    this->callState = callState;
    if (blinkTimer.isActive()) {
        blinkTimer.stop();
        QPalette palette = dialLineEdit->palette();
        palette.setColor(dialLineEdit->foregroundRole(), Qt::red);
        dialLineEdit->setPalette(palette);
    }

    switch (callState) {
        case SIPCall::STATE_CONFIRMED :            
            dialButton->setEnabled(false);
            hangupButton->setEnabled(true);
            dialLineEdit->setEnabled(false);
            break;

        case SIPCall::STATE_DISCONNECTED :
            dialButton->setEnabled(true);
            hangupButton->setEnabled(false);
            dialLineEdit->setEnabled(true);
            {
                QPalette palette = dialLineEdit->palette();
                palette.setColor(dialLineEdit->foregroundRole(), Qt::black);
                dialLineEdit->setPalette(palette);
            }
            break;

        case SIPCall::STATE_INCOMING :
            dialButton->setIcon(QIcon(":/icons/play.png"));
            dialButton->setEnabled(true);
            hangupButton->setEnabled(true);
            dialLineEdit->setEnabled(false);
            {
                QString number = call.getNumber();
                dialLineEdit->setText(number);
            }
            blinkTimer.start();
            break;

    }
}

void DialPad::onBlinkTimeout()
{
    QPalette palette = dialLineEdit->palette();

    if (palette.color(dialLineEdit->foregroundRole()) == Qt::red) {
        palette.setColor(dialLineEdit->foregroundRole(), Qt::gray);
    }
    else {
        palette.setColor(dialLineEdit->foregroundRole(), Qt::red);
    }

    dialLineEdit->setPalette(palette);
}

void DialPad::on_dialButton_clicked()
{
    switch (callState) {

        case SIPCall::STATE_DISCONNECTED :
        case SIPCall::STATE_NULL : {
            QString number = dialLineEdit->text();
            if (!number.isEmpty()) {
                dialButton->setEnabled(false);
                emit call("sip:" + number);
            }

            break;
        }

        case SIPCall::STATE_INCOMING :
            emit answer();
            break;

        default :
            break;

    }
}

void DialPad::on_hangupButton_clicked()
{
    switch (callState) {
        case SIPCall::STATE_INCOMING :
        case SIPCall::STATE_CONFIRMED :
            emit hangup();
            break;

        default :
            break;

    }
}

void DialPad::on_statusButton_triggered(QAction *action)
{
    if (action == onlineAction) {
        emit setOnlineState(Phone::ONLINE);
    }
    else if (action == offlineAction) {
        emit setOnlineState(Phone::OFFLINE);
    }
}

void DialPad::addDigit(const QString &digit)
{
    dialLineEdit->insert(digit);
    if (callState == SIPCall::STATE_CONFIRMED) {
        emit dialDTMF(digit);
    }
}

void DialPad::replaceDigit(const QString &digit)
{
    QString text = dialLineEdit->text();
    if (!text.isEmpty()) {
        text.resize(text.size() - 1);
        dialLineEdit->setText(text + digit);
    }
}

void DialPad::removeDigit()
{
    QString text = dialLineEdit->text();
    if (!text.isEmpty()) {
        text.resize(text.size() - 1);
        dialLineEdit->setText(text);
    }
}

void DialPad::setNumber(const QString &number)
{
    dialLineEdit->setText(number);
}

void DialPad::setCompleterList(const QStringList &wordList)
{
    delete completer;
    completer = new QCompleter(wordList, this);
    dialLineEdit->setCompleter(completer);
}

void DialPad::onPhoneStateChanged(int state)
{
    switch (state) {
        case Phone::INITIALIZED :

            break;
    }
}

void DialPad::onAccountStateChanged(int state)
{
    switch (state) {
        case Phone::NO_REGISTRATION :
            dialButton->setEnabled(true);
            statusButton->setDefaultAction(offlineAction);
            statusButton->setEnabled(false);
            break;

        case Phone::REGISTERED :
            dialButton->setEnabled(true);
            statusButton->setEnabled(true);
            break;

        case Phone::UNREGISTERED :
            QMessageBox::warning(this, "Registration error", "Account registration failed.\nPlease check your account configuration.");
            dialButton->setEnabled(false);
            statusButton->setDefaultAction(offlineAction);
            statusButton->setEnabled(false);
            break;
    }
}

void DialPad::onOnlineStateChanged(int state)
{
    switch (state) {
        case Phone::ONLINE :
            statusButton->setDefaultAction(onlineAction);
            break;

        case Phone::OFFLINE :
            statusButton->setDefaultAction(offlineAction);
            break;
    }
}

void DialPad::onPhoneErrorOccured(int state)
{
    switch (state) {
        case Phone::CREATION_FAILED :
            QMessageBox::critical(this, "SIP Stack error", "SIP Stack creation failed.");
            break;

        case Phone::INITIALIZATION_FAILED :
            QMessageBox::critical(this, "SIP phone error", "SIP Stack initialization failed.\nPlease check your connection.");
            dialButton->setEnabled(false);
            statusButton->setEnabled(false);
            break;

        case Phone::TRANSPORT_CREATION_FAILED :
            QMessageBox::critical(this, "SIP phone error", "SIP transport creation failed.\nPlease check your connection.");
            break;

        case Phone::ACCOUNT_CREATION_FAILED :
            dialButton->setEnabled(false);
            statusButton->setEnabled(false);
            QMessageBox::critical(this, "Account error", "Account creation failed.\nPlease check your account settings.");
            break;
    }
}
