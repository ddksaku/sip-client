/********************************************************************************
** Form generated from reading ui file 'MainWindow.ui'
**
** Created: Wed Oct 14 23:13:08 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAboutApplication;
    QAction *actionAccount;
    QAction *actionNetwork;
    QAction *actionExit;
    QAction *actionScreenshot;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuConfiguration;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        actionAboutApplication = new QAction(MainWindow);
        actionAboutApplication->setObjectName(QString::fromUtf8("actionAboutApplication"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/sub.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAboutApplication->setIcon(icon);
        actionAccount = new QAction(MainWindow);
        actionAccount->setObjectName(QString::fromUtf8("actionAccount"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/pref_advanced.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAccount->setIcon(icon1);
        actionNetwork = new QAction(MainWindow);
        actionNetwork->setObjectName(QString::fromUtf8("actionNetwork"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/prefs.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNetwork->setIcon(icon2);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon3);
        actionScreenshot = new QAction(MainWindow);
        actionScreenshot->setObjectName(QString::fromUtf8("actionScreenshot"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/screenshot.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScreenshot->setIcon(icon4);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuConfiguration = new QMenu(menubar);
        menuConfiguration->setObjectName(QString::fromUtf8("menuConfiguration"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuConfiguration->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionExit);
        menuConfiguration->addAction(actionAccount);
        menuConfiguration->addAction(actionNetwork);
        menuAbout->addAction(actionAboutApplication);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Chatty", 0, QApplication::UnicodeUTF8));
        actionAboutApplication->setText(QApplication::translate("MainWindow", "About application", 0, QApplication::UnicodeUTF8));
        actionAccount->setText(QApplication::translate("MainWindow", "Account", 0, QApplication::UnicodeUTF8));
        actionNetwork->setText(QApplication::translate("MainWindow", "Network", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionScreenshot->setText(QApplication::translate("MainWindow", "Make screenshot", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuConfiguration->setTitle(QApplication::translate("MainWindow", "Configuration", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
