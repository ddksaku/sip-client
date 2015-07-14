#ifndef __NetworkDialog__
#define	__NetworkDialog__

#include <QDialog>
#include "ui_NetworkDialog.h"
#include "Network.h"

class NetworkDialog : public QDialog, public Ui::NetworkDialog {

        Q_OBJECT
    
    private :
        Network network;
        bool edited;
        
    public :
        NetworkDialog(QWidget* parent = 0);

    signals :
        void networkChanged(const Network &network);

    private slots :
        void on_stunCheckBox_stateChanged(int state);
        void on_proxyCheckBox_stateChanged(int state);
        void on_proxyLineEdit_editingFinished();
        void on_portLineEdit_editingFinished();
        void on_stunLineEdit_editingFinished();
        void on_buttonBox_accepted();
        void on_buttonBox_rejected();
        
};

#endif	/* __NetworkDialog__ */
