#ifndef __ProxyDialog__
#define __ProxyDialog__

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class ProxyDialog : public QDialog {
    
        Q_OBJECT;
    
    private :
        QLabel *proxyLabel;
        QLabel *portLabel;
        
        QLineEdit *proxyLineEdit;
        QLineEdit *portLineEdit;
        
        QPushButton *okButton;
    
    public :
        ProxyDialog(QWidget *parent);
        ~ProxyDialog();
        
    private slots :
        void proxyEdited();
        void portEdited();
};

#endif /* __ProxyDialog__ */
