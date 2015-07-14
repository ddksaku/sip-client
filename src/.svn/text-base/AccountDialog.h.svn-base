#ifndef __AccountDialog__
#define __AccountDialog__

#include <QtCore/QList>
#include <QtGui/QDialog>
#include "ui_AccountDialog.h"
#include "ui/Error.h"
#include "Account.h"

class QLabel;
class QLineEdit;
class QPushButton;

class AccountDialog : public QDialog, public Ui::AccountDialog {

        Q_OBJECT

    private :
        Account account;
        bool edited;

    public :
        AccountDialog(QWidget *parent);
        ~AccountDialog();

        QList<ui::Error> validate();

    signals :
        void accountChanged(const Account &account);

    private slots :
        void accountEdited();
        void okClicked();
        void cancelClicked();
};

#endif /* __AccountDialog__ */
