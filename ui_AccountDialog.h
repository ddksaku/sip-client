/********************************************************************************
** Form generated from reading ui file 'AccountDialog.ui'
**
** Created: Wed Oct 14 23:13:08 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ACCOUNTDIALOG_H
#define UI_ACCOUNTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AccountDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *titleLabel;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLabel *registrarLabel;
    QVBoxLayout *verticalLayout;
    QLineEdit *titleLineEdit;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *registrarLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *AccountDialog)
    {
        if (AccountDialog->objectName().isEmpty())
            AccountDialog->setObjectName(QString::fromUtf8("AccountDialog"));
        AccountDialog->resize(272, 174);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/pref_advanced.png"), QSize(), QIcon::Normal, QIcon::Off);
        AccountDialog->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(AccountDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        titleLabel = new QLabel(AccountDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));

        verticalLayout_2->addWidget(titleLabel);

        usernameLabel = new QLabel(AccountDialog);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        verticalLayout_2->addWidget(usernameLabel);

        passwordLabel = new QLabel(AccountDialog);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        verticalLayout_2->addWidget(passwordLabel);

        registrarLabel = new QLabel(AccountDialog);
        registrarLabel->setObjectName(QString::fromUtf8("registrarLabel"));

        verticalLayout_2->addWidget(registrarLabel);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLineEdit = new QLineEdit(AccountDialog);
        titleLineEdit->setObjectName(QString::fromUtf8("titleLineEdit"));

        verticalLayout->addWidget(titleLineEdit);

        usernameLineEdit = new QLineEdit(AccountDialog);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));

        verticalLayout->addWidget(usernameLineEdit);

        passwordLineEdit = new QLineEdit(AccountDialog);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordLineEdit);

        registrarLineEdit = new QLineEdit(AccountDialog);
        registrarLineEdit->setObjectName(QString::fromUtf8("registrarLineEdit"));

        verticalLayout->addWidget(registrarLineEdit);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(AccountDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

#ifndef QT_NO_SHORTCUT
        titleLabel->setBuddy(titleLineEdit);
        usernameLabel->setBuddy(usernameLineEdit);
        passwordLabel->setBuddy(passwordLineEdit);
        registrarLabel->setBuddy(registrarLineEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(titleLineEdit, usernameLineEdit);
        QWidget::setTabOrder(usernameLineEdit, passwordLineEdit);
        QWidget::setTabOrder(passwordLineEdit, registrarLineEdit);
        QWidget::setTabOrder(registrarLineEdit, buttonBox);

        retranslateUi(AccountDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AccountDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AccountDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AccountDialog);
    } // setupUi

    void retranslateUi(QDialog *AccountDialog)
    {
        AccountDialog->setWindowTitle(QApplication::translate("AccountDialog", "Account settings", 0, QApplication::UnicodeUTF8));
        titleLabel->setText(QApplication::translate("AccountDialog", "Title:", 0, QApplication::UnicodeUTF8));
        usernameLabel->setText(QApplication::translate("AccountDialog", "Username:", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("AccountDialog", "Password:", 0, QApplication::UnicodeUTF8));
        registrarLabel->setText(QApplication::translate("AccountDialog", "Registrar:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(AccountDialog);
    } // retranslateUi

};

namespace Ui {
    class AccountDialog: public Ui_AccountDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTDIALOG_H
