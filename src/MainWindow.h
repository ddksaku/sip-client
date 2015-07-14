#ifndef __MainWindow__
#define __MainWindow__

#include <QMainWindow>
#include "ui_MainWindow.h"
#include "logging/Logger.h"
#include "Call.h"
#include "Phone.h"

class DialPad;
class AccountDialog;
class NetworkDialog;
class ProxyDialog;
class DialerWidget;
class HistoryWidget;
class GLWidget;
class QTabWidget;
class QString;

class MainWindow : public QMainWindow, public Ui::MainWindow {

        Q_OBJECT;

    private :
        Phone phone;

        DialPad *dialPad;

        DialerWidget *dialerWidget;
        HistoryWidget *historyWidget;
        GLWidget *glWidget;

        NetworkDialog *networkDialog;
        AccountDialog *accountDialog;
        ProxyDialog *proxyDialog;

        QTabWidget *tabWidget;
        micro::logging::Logger logger;

    private slots :
        void configureAccount();
        void configureNetwork();
        void callStateChanged(Call call, int callState);
        void tabChanged(int index);
        //void makeScreenshot();

    public :
        MainWindow(QWidget *parent = 0);
        ~MainWindow();
};

#endif /* __MainWindow__ */
