/********************************************************************************
** Form generated from reading ui file 'NetworkDialog.ui'
**
** Created: Wed Oct 14 23:13:08 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_NETWORKDIALOG_H
#define UI_NETWORKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkDialog
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *proxyGroupBox;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout;
    QCheckBox *proxyCheckBox;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout1;
    QLabel *proxyLabel;
    QLineEdit *proxyLineEdit;
    QLabel *portLabel;
    QLineEdit *portLineEdit;
    QGroupBox *natGroupBox;
    QVBoxLayout *vboxLayout2;
    QHBoxLayout *hboxLayout2;
    QCheckBox *stunCheckBox;
    QSpacerItem *spacerItem1;
    QHBoxLayout *hboxLayout3;
    QLabel *stunLabel;
    QLineEdit *stunLineEdit;
    QHBoxLayout *hboxLayout4;
    QSpacerItem *spacerItem2;
    QDialogButtonBox *buttonBox;
    QSpacerItem *spacerItem3;

    void setupUi(QWidget *NetworkDialog)
    {
        if (NetworkDialog->objectName().isEmpty())
            NetworkDialog->setObjectName(QString::fromUtf8("NetworkDialog"));
        NetworkDialog->resize(278, 252);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/prefs.png"), QSize(), QIcon::Normal, QIcon::Off);
        NetworkDialog->setWindowIcon(icon);
        vboxLayout = new QVBoxLayout(NetworkDialog);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        proxyGroupBox = new QGroupBox(NetworkDialog);
        proxyGroupBox->setObjectName(QString::fromUtf8("proxyGroupBox"));
        proxyGroupBox->setEnabled(false);
        vboxLayout1 = new QVBoxLayout(proxyGroupBox);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        proxyCheckBox = new QCheckBox(proxyGroupBox);
        proxyCheckBox->setObjectName(QString::fromUtf8("proxyCheckBox"));

        hboxLayout->addWidget(proxyCheckBox);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);


        vboxLayout1->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        proxyLabel = new QLabel(proxyGroupBox);
        proxyLabel->setObjectName(QString::fromUtf8("proxyLabel"));

        hboxLayout1->addWidget(proxyLabel);

        proxyLineEdit = new QLineEdit(proxyGroupBox);
        proxyLineEdit->setObjectName(QString::fromUtf8("proxyLineEdit"));

        hboxLayout1->addWidget(proxyLineEdit);

        portLabel = new QLabel(proxyGroupBox);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));

        hboxLayout1->addWidget(portLabel);

        portLineEdit = new QLineEdit(proxyGroupBox);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));
        portLineEdit->setMaximumSize(QSize(54, 16777215));
        portLineEdit->setMaxLength(5);
        portLineEdit->setFrame(true);
        portLineEdit->setReadOnly(false);

        hboxLayout1->addWidget(portLineEdit);


        vboxLayout1->addLayout(hboxLayout1);


        vboxLayout->addWidget(proxyGroupBox);

        natGroupBox = new QGroupBox(NetworkDialog);
        natGroupBox->setObjectName(QString::fromUtf8("natGroupBox"));
        vboxLayout2 = new QVBoxLayout(natGroupBox);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        stunCheckBox = new QCheckBox(natGroupBox);
        stunCheckBox->setObjectName(QString::fromUtf8("stunCheckBox"));

        hboxLayout2->addWidget(stunCheckBox);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem1);


        vboxLayout2->addLayout(hboxLayout2);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        stunLabel = new QLabel(natGroupBox);
        stunLabel->setObjectName(QString::fromUtf8("stunLabel"));

        hboxLayout3->addWidget(stunLabel);

        stunLineEdit = new QLineEdit(natGroupBox);
        stunLineEdit->setObjectName(QString::fromUtf8("stunLineEdit"));

        hboxLayout3->addWidget(stunLineEdit);


        vboxLayout2->addLayout(hboxLayout3);


        vboxLayout->addWidget(natGroupBox);

        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerItem2);

        buttonBox = new QDialogButtonBox(NetworkDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        hboxLayout4->addWidget(buttonBox);

        spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerItem3);


        vboxLayout->addLayout(hboxLayout4);

        QWidget::setTabOrder(proxyCheckBox, proxyLineEdit);
        QWidget::setTabOrder(proxyLineEdit, portLineEdit);
        QWidget::setTabOrder(portLineEdit, stunCheckBox);
        QWidget::setTabOrder(stunCheckBox, stunLineEdit);

        retranslateUi(NetworkDialog);

        QMetaObject::connectSlotsByName(NetworkDialog);
    } // setupUi

    void retranslateUi(QWidget *NetworkDialog)
    {
        NetworkDialog->setWindowTitle(QApplication::translate("NetworkDialog", "Network settings", 0, QApplication::UnicodeUTF8));
        proxyGroupBox->setTitle(QApplication::translate("NetworkDialog", "Proxy settings", 0, QApplication::UnicodeUTF8));
        proxyCheckBox->setText(QApplication::translate("NetworkDialog", "Use proxy", 0, QApplication::UnicodeUTF8));
        proxyLabel->setText(QApplication::translate("NetworkDialog", "Proxy:", 0, QApplication::UnicodeUTF8));
        portLabel->setText(QApplication::translate("NetworkDialog", ":", 0, QApplication::UnicodeUTF8));
        natGroupBox->setTitle(QApplication::translate("NetworkDialog", "NAT settings", 0, QApplication::UnicodeUTF8));
        stunCheckBox->setText(QApplication::translate("NetworkDialog", "Use STUN", 0, QApplication::UnicodeUTF8));
        stunLabel->setText(QApplication::translate("NetworkDialog", "STUN server:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NetworkDialog);
    } // retranslateUi

};

namespace Ui {
    class NetworkDialog: public Ui_NetworkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKDIALOG_H
