#include "NetworkDialog.h"
#include <QtCore/QSettings>
#include <QtGui/QMessageBox>

NetworkDialog::NetworkDialog(QWidget *parent) : QDialog(parent), edited(false)
{
    setupUi(this);
    
    // read settings
    QSettings settings;
    settings.beginGroup("settings");
        settings.beginGroup("proxy");
            network.setUseProxy(settings.value("use", QVariant(false)).toBool());
            network.setProxy(settings.value("proxy").toString());
            network.setPort(settings.value("port").toString());
        settings.endGroup();
        
        settings.beginGroup("stun");
            network.setUseSTUN(settings.value("use", QVariant(false)).toBool());
            network.setSTUN(settings.value("server").toString());
        settings.endGroup();
    settings.endGroup();
    
    proxyLineEdit->setText(network.getProxy());
    portLineEdit->setText(network.getPort());
    if (network.getUseProxy()) {
        proxyCheckBox->setCheckState(Qt::Checked);
        proxyLineEdit->setEnabled(true);
        portLineEdit->setEnabled(true);
    }
    else {
        proxyCheckBox->setCheckState(Qt::Unchecked);
        proxyLineEdit->setEnabled(false);
        portLineEdit->setEnabled(false);
    }
    
    stunLineEdit->setText(network.getSTUN());
    if (network.getUseSTUN()) {
        stunCheckBox->setCheckState(Qt::Checked);
        stunLineEdit->setEnabled(true);
    }
    else {
        stunCheckBox->setCheckState(Qt::Unchecked);
        stunLineEdit->setEnabled(false);
    }
    
}

void NetworkDialog::on_stunCheckBox_stateChanged(int state)
{
    switch (state) {
        case Qt::Checked :
            stunLineEdit->setEnabled(true);
            break;
            
        default :
            stunLineEdit->setEnabled(false);
            break;
    }
    
    edited = true;
}

void NetworkDialog::on_proxyCheckBox_stateChanged(int state)
{
    switch (state) {
        case Qt::Checked :
            proxyLineEdit->setEnabled(true);
            portLineEdit->setEnabled(true);
            break;
            
        default :
            proxyLineEdit->setEnabled(false);
            portLineEdit->setEnabled(false);
            break;
    }
    
    edited = true;
}

void NetworkDialog::on_proxyLineEdit_editingFinished()
{
    edited = true;
}

void NetworkDialog::on_portLineEdit_editingFinished()
{
    edited = true;
}

void NetworkDialog::on_stunLineEdit_editingFinished()
{
    edited = true;
}

void NetworkDialog::on_buttonBox_accepted()
{
    close();
    
    if (edited) {
        edited = false;
        
        network.setUseProxy(proxyCheckBox->checkState() == Qt::Checked);
        network.setProxy(proxyLineEdit->text());
        network.setPort(portLineEdit->text());
        
        network.setUseSTUN(stunCheckBox->checkState() == Qt::Checked);
        network.setSTUN(stunLineEdit->text());
        
        QSettings settings;
        settings.beginGroup("settings");
            settings.beginGroup("proxy");
                settings.setValue("use", network.getUseProxy());
                settings.setValue("proxy", network.getProxy());
                settings.setValue("port", network.getPort());
            settings.endGroup();
            settings.beginGroup("stun");
                settings.setValue("use", network.getUseSTUN());
                settings.setValue("server", network.getSTUN());
            settings.endGroup();
        settings.endGroup();

        emit networkChanged(network);
        QMessageBox::information(this, "Information", "The changes will be applied the next time you start up the application.");
    }
}

void NetworkDialog::on_buttonBox_rejected()
{
    close();
    
    if (edited) {
        edited = false;
        
        proxyLineEdit->setText(network.getProxy());
        portLineEdit->setText(network.getPort());
        if (network.getUseProxy()) {
            proxyCheckBox->setCheckState(Qt::Checked);
            proxyLineEdit->setEnabled(true);
            portLineEdit->setEnabled(true);
        }
        else {
            proxyCheckBox->setCheckState(Qt::Unchecked);
            proxyLineEdit->setEnabled(false);
            portLineEdit->setEnabled(false);
        }

        stunLineEdit->setText(network.getSTUN());
        if (network.getUseSTUN()) {
            stunCheckBox->setCheckState(Qt::Checked);
            stunLineEdit->setEnabled(true);
        }
        else {
            stunCheckBox->setCheckState(Qt::Unchecked);
            stunLineEdit->setEnabled(false);
        }
    }
}
