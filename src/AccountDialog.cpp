#include "AccountDialog.h"
#include <QtCore/QSettings>
#include <QtGui/QMessageBox>

AccountDialog::AccountDialog(QWidget *parent) : QDialog(parent), edited(false)
{
    setupUi(this);

    // read settings
    QSettings settings;
    settings.beginGroup("accounts");
        settings.beginGroup("default");
            account.setTitle(settings.value("title").toString());
            account.setUsername(settings.value("username").toString());
            account.setPassword(settings.value("password").toString());
            account.setRegistrar(settings.value("registrar").toString());
        settings.endGroup();
    settings.endGroup();

    titleLineEdit->setText(account.getTitle());
    usernameLineEdit->setText(account.getUsername());
    passwordLineEdit->setText(account.getPassword());
    registrarLineEdit->setText(account.getRegistrar());
    
    // signals and slots connection
    connect(titleLineEdit, SIGNAL(editingFinished()), this, SLOT(accountEdited()));
    connect(usernameLineEdit, SIGNAL(editingFinished()), this, SLOT(accountEdited()));
    connect(passwordLineEdit, SIGNAL(editingFinished()), this, SLOT(accountEdited()));
    connect(registrarLineEdit, SIGNAL(editingFinished()), this, SLOT(accountEdited()));

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(okClicked()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(cancelClicked()));

}

AccountDialog::~AccountDialog()
{
}

void AccountDialog::accountEdited()
{
    edited = true;
}

void AccountDialog::okClicked()
{
    QList<ui::Error> errors = validate();
    if (!errors.isEmpty()) {
        QString message("Errors:");
        foreach (ui::Error error, errors) {
            message.append("\n - " + error.getMessage());
        }

        QMessageBox::critical(this, "Validation error", message);
        show();
        return;
    }

    close();
    
    if (edited) {
        edited = false;
        account.setTitle(titleLineEdit->text());
        account.setUsername(usernameLineEdit->text());
        account.setPassword(passwordLineEdit->text());
        account.setRegistrar(registrarLineEdit->text());

        QSettings settings;
        settings.beginGroup("accounts");
            settings.beginGroup("default");
                settings.setValue("title", account.getTitle());
                settings.setValue("username", account.getUsername());
                settings.setValue("password", account.getPassword());
                settings.setValue("registrar", account.getRegistrar());
            settings.endGroup();
        settings.endGroup();

        emit accountChanged(account);
    }
}

void AccountDialog::cancelClicked()
{    
    close();
    
    if (edited) {
        edited = false;
        titleLineEdit->setText(account.getTitle());
        usernameLineEdit->setText(account.getUsername());
        passwordLineEdit->setText(account.getPassword());
        registrarLineEdit->setText(account.getRegistrar());
    }
}

QList<ui::Error> AccountDialog::validate()
{
    QList<ui::Error> errors;

    if (usernameLineEdit->text().isEmpty()) {
        errors.append(ui::Error("Username must be filled."));
    }

    if (passwordLineEdit->text().isEmpty()) {
        errors.append(ui::Error("Password must be filled."));
    }

    if (registrarLineEdit->text().isEmpty()) {
        errors.append(ui::Error("Registrar must be filled."));
    }

    return errors;
}
