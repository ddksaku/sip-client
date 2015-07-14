/********************************************************************************
** Form generated from reading ui file 'DialPad.ui'
**
** Created: Wed Oct 14 23:13:08 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DIALPAD_H
#define UI_DIALPAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialPad
{
public:
    QAction *onlineAction;
    QAction *offlineAction;
    QHBoxLayout *horizontalLayout;
    QToolButton *statusButton;
    QFrame *line;
    QLineEdit *dialLineEdit;
    QPushButton *dialButton;
    QPushButton *hangupButton;

    void setupUi(QWidget *DialPad)
    {
        if (DialPad->objectName().isEmpty())
            DialPad->setObjectName(QString::fromUtf8("DialPad"));
        DialPad->resize(289, 50);
        onlineAction = new QAction(DialPad);
        onlineAction->setObjectName(QString::fromUtf8("onlineAction"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/online.png"), QSize(), QIcon::Normal, QIcon::Off);
        onlineAction->setIcon(icon);
        offlineAction = new QAction(DialPad);
        offlineAction->setObjectName(QString::fromUtf8("offlineAction"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/offline.png"), QSize(), QIcon::Normal, QIcon::Off);
        offlineAction->setIcon(icon1);
        horizontalLayout = new QHBoxLayout(DialPad);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        statusButton = new QToolButton(DialPad);
        statusButton->setObjectName(QString::fromUtf8("statusButton"));
        statusButton->setEnabled(false);
        statusButton->setIcon(icon1);
        statusButton->setPopupMode(QToolButton::InstantPopup);

        horizontalLayout->addWidget(statusButton);

        line = new QFrame(DialPad);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        dialLineEdit = new QLineEdit(DialPad);
        dialLineEdit->setObjectName(QString::fromUtf8("dialLineEdit"));

        horizontalLayout->addWidget(dialLineEdit);

        dialButton = new QPushButton(DialPad);
        dialButton->setObjectName(QString::fromUtf8("dialButton"));
        dialButton->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        dialButton->setIcon(icon2);

        horizontalLayout->addWidget(dialButton);

        hangupButton = new QPushButton(DialPad);
        hangupButton->setObjectName(QString::fromUtf8("hangupButton"));
        hangupButton->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/hangup.png"), QSize(), QIcon::Normal, QIcon::Off);
        hangupButton->setIcon(icon3);

        horizontalLayout->addWidget(hangupButton);


        retranslateUi(DialPad);

        QMetaObject::connectSlotsByName(DialPad);
    } // setupUi

    void retranslateUi(QWidget *DialPad)
    {
        DialPad->setWindowTitle(QApplication::translate("DialPad", "Form", 0, QApplication::UnicodeUTF8));
        onlineAction->setText(QApplication::translate("DialPad", "Online", 0, QApplication::UnicodeUTF8));
        offlineAction->setText(QApplication::translate("DialPad", "Offline", 0, QApplication::UnicodeUTF8));
        statusButton->setText(QApplication::translate("DialPad", "Offline", 0, QApplication::UnicodeUTF8));
        dialButton->setText(QString());
        hangupButton->setText(QString());
        Q_UNUSED(DialPad);
    } // retranslateUi

};

namespace Ui {
    class DialPad: public Ui_DialPad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALPAD_H
