#ifndef __DialerWidget__
#define	__DialerWidget__

#include <QtGui/QDialog>
#include <QtCore/QString>
#include <QtCore/QTimer>
#include "ui_DialerWidget.h"


/**
 * Dialer widget. This widget represents phone dialer.
 */
class DialerWidget : public QDialog, public Ui::DialerWidget {

        Q_OBJECT

    public :

        enum Layout {
            LAYOUT_123 = 0,
            LAYOUT_ABC = 1
        };

    private :
        Layout layout;
        QString buttonsLayout[2][11];
        QTimer *timer;
        int currentButton;
        int currentCharacter;

    public :

        /** Constructor. */
        DialerWidget(QWidget *parent = 0);

    private :
        void buttonClicked(int index);

    signals :
        /** Emits signal to add the digit. */
        void addDigit(const QString &digit);

        /** Emits signal to replace last digit. */
        void replaceDigit(const QString &digit);

        /** Emits signal to remove last digit. */
        void removeDigit();

    public slots :
        /** Changes dialer's layout. */
        void changeLayout(Layout layout);

        /** Processes timeout. */
        void onTimeout();

    private slots :
        void on_oneButton_clicked();
        void on_twoButton_clicked();
        void on_threeButton_clicked();
        void on_fourButton_clicked();
        void on_fiveButton_clicked();
        void on_sixButton_clicked();
        void on_sevenButton_clicked();
        void on_eightButton_clicked();
        void on_nineButton_clicked();
        void on_zeroButton_clicked();
        void on_layoutButton_clicked();
        void on_backspaceButton_clicked();

};

#endif	/* __DialerWidget__ */
