#include "MainWindow.h"
#include "DialPad.h"
#include "AccountDialog.h"
#include "NetworkDialog.h"
#include "DialerWidget.h"
#include "HistoryWidget.h"
#include "HistoryModel.h"
#include "GLWidget.h"
#include "ProxyDialog.h"
#include <QtGui/QApplication>
#include <QtGui/QVBoxLayout>
#include <QtGui/QTabWidget>
#include <QtGui/QMessageBox>
#include <QtGui/QDesktopWidget>
#include <QtGui/QPixmap>
#include <QtCore/QSettings>
#include <QtCore/QString>



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), logger("MainWindow")
{
    setupUi(this);

    accountDialog = 0;
    networkDialog = 0;
    proxyDialog = 0;

    QCoreApplication::setOrganizationName("Maverick");
    QCoreApplication::setOrganizationDomain("http://maverick.webz.cz/3DHead/");
    QCoreApplication::setApplicationName("Chatty");

    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);
    centralWidget()->setLayout(vBoxLayout);

    dialPad = new DialPad(this);
    vBoxLayout->addWidget(dialPad);

    tabWidget = new QTabWidget(this);
    vBoxLayout->addWidget(tabWidget);

    dialerWidget = new DialerWidget(tabWidget);
    historyWidget = new HistoryWidget(tabWidget);
    glWidget = new GLWidget(tabWidget);

    tabWidget->addTab(dialerWidget, QIcon(":/icons/url.png"), tr("Dialer"));
    tabWidget->addTab(historyWidget, QIcon(":/icons/logs.png"), tr("History"));
    tabWidget->addTab(glWidget, QIcon(":/icons/video_size.png"), tr("Video"));

    // registering all metatypes used as QVariant
    int id = qRegisterMetaType<Call>();

    // connecting menu actions
    connect(actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(actionAccount, SIGNAL(triggered()), this, SLOT(configureAccount()));
    connect(actionNetwork, SIGNAL(triggered()), this, SLOT(configureNetwork()));
    //connect(actionScreenshot, SIGNAL(triggered()), this, SLOT(makeScreenshot()));    

    // connecting dialpad to phone
    connect(dialPad, SIGNAL(call(const QString &)), &phone, SLOT(call(const QString &)));
    connect(dialPad, SIGNAL(hangup()), &phone, SLOT(hangup()));
    connect(dialPad, SIGNAL(answer()), &phone, SLOT(answer()));
    connect(dialPad, SIGNAL(setOnlineState(int)), &phone, SLOT(setOnlineState(int)));
    connect(&phone, SIGNAL(callStateChanged(Call, int)), dialPad, SLOT(onCallStateChanged(Call, int)));
    connect(&phone, SIGNAL(accountStateChanged(int)), dialPad, SLOT(onAccountStateChanged(int)));
    connect(&phone, SIGNAL(onlineStateChanged(int)), dialPad, SLOT(onOnlineStateChanged(int)));
    connect(&phone, SIGNAL(phoneStateChanged(int)), dialPad, SLOT(onPhoneStateChanged(int)));
    connect(&phone, SIGNAL(errorOccured(int)), dialPad, SLOT(onPhoneErrorOccured(int)));


    // connecting dialer to dialpad
    connect(dialerWidget, SIGNAL(addDigit(const QString &)), dialPad, SLOT(addDigit(const QString &)));
    connect(dialerWidget, SIGNAL(replaceDigit(const QString &)), dialPad, SLOT(replaceDigit(const QString &)));
    connect(dialerWidget, SIGNAL(removeDigit()), dialPad, SLOT(removeDigit()));

    // connecting history widget to dialpad
    connect(historyWidget, SIGNAL(call(const QString&)), dialPad, SLOT(setNumber(const QString&)));
    connect(historyWidget, SIGNAL(historyChanged(const QStringList &)), dialPad, SLOT(setCompleterList(const QStringList &)));

    // connecting phone to history widget
    connect(&phone, SIGNAL(callStateChanged(Call, int)), historyWidget, SLOT(onCallStateChanged(Call, int)));

    // Connection to change current widget on call and on incoming call
    connect(&phone, SIGNAL(callStateChanged(Call, int)), this, SLOT(callStateChanged(Call, int)));

    // connecting tab widget to main window
    connect(tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabChanged(int)));

    // setting the completer list to dialpad
    dialPad->setCompleterList(historyWidget->getHistoryModel()->getCompleterList());

    // start SIP phone thread
    phone.start();
}

MainWindow::~MainWindow()
{
    // terminate SIP phone thread and wait
    phone.exit();
    phone.wait();
}

void MainWindow::configureAccount()
{
    if (!accountDialog) {
        accountDialog = new AccountDialog(this);
        connect(accountDialog, SIGNAL(accountChanged(const Account &)), &phone, SLOT(changeAccount(const Account &)));
    }

    accountDialog->show();
    accountDialog->activateWindow();
}

void MainWindow::configureNetwork()
{
    if (!networkDialog) {
        networkDialog = new NetworkDialog(this);
        connect(networkDialog, SIGNAL(networkChanged(const Network &)), &phone, SLOT(changeNetwork(const Network &)));
    }

    networkDialog->show();
    networkDialog->activateWindow();
}

void MainWindow::callStateChanged(Call, int callState)
{
    switch (callState) {
        case micro::voip::SIPCall::STATE_INCOMING :
            tabWidget->setCurrentWidget(dialerWidget);
            break;
    }
}

void MainWindow::tabChanged(int index)
{
    switch (index) {
        case 0 :
        case 1 :
            dialPad->show();
            break;
        case 2 :
            dialPad->hide();
            break;
        default :
            break;
    }
}

/*void MainWindow::makeScreenshot()
{
    QPixmap pixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
    pixmap.save("screenshot.png", "PNG");
}
*/
