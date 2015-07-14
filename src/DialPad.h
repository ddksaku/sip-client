#ifndef __DialPad__
#define __DialPad__

#include "Call.h"
#include "ui_DialPad.h"
#include <QtGui/QDialog>
#include <QtCore/QStringList>
#include <QtCore/QTimer>

/**
 * Dialpad widget. This widget represents phone dialer.
 */
class DialPad : public QDialog, public Ui::DialPad {

        Q_OBJECT

    private :
        QCompleter *completer;  /**< Dial completer. */
        int callState;    /**< Call state. */
        QTimer blinkTimer; /**< Blink timer. */

    public :

        /** Constructor. */
        DialPad(QWidget *parent = 0);

    signals :
        void call(const QString &number);
        void hangup();
        void answer();
        void dialDTMF(const QString &digits);
        void setOnlineState(int state);

    public slots :
        /** Changes the dialpad widget depending on call state. */
        void onCallStateChanged(Call call, int callState);
        void onPhoneStateChanged(int state);
        void onAccountStateChanged(int state);
        void onOnlineStateChanged(int state);
        void onPhoneErrorOccured(int state);

        /** Adds digit to the dial number. */
        void addDigit(const QString &digit);

        /** Removes last digit. */
        void removeDigit();

        /** Replaces last digit. */
        void replaceDigit(const QString &digit);

        /** Sets number to dialer text box. */
        void setNumber(const QString &number);

        /** Sets completer list. */
        void setCompleterList(const QStringList &list);

    private slots :
        /** Processes the dial button click event. */
        void on_dialButton_clicked();

        /** Processes the hangup button click event. */
        void on_hangupButton_clicked();


        /** Processes the status tool button trigger event. */
        void on_statusButton_triggered(QAction *action);

        /** Processes the blink timer event. */
        void onBlinkTimeout();

};

#endif /* __DialPad__ */

