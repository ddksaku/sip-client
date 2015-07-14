#include "ProxyDialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSettings>

ProxyDialog::ProxyDialog(QWidget *parent) : QDialog(parent)
{
    proxyLabel = new QLabel(tr("Proxy:"));
    portLabel = new QLabel(tr(":"));
    
    proxyLineEdit = new QLineEdit;
    portLineEdit = new QLineEdit;
    portLineEdit->setMaxLength(5);
    
    okButton = new QPushButton(tr("OK"));
    connect(okButton, SIGNAL(clicked()), this, SLOT(close()));
    
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(proxyLabel);
    topLayout->addWidget(proxyLineEdit);
    topLayout->addWidget(portLabel);
    topLayout->addWidget(portLineEdit);
    
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(okButton);
    bottomLayout->addStretch();
    
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);
    
    setLayout(mainLayout);
}

ProxyDialog::~ProxyDialog()
{

}

void ProxyDialog::proxyEdited()
{
    QSettings settings;
    settings.setValue("settings/proxy", proxyLineEdit->text());
}

void ProxyDialog::portEdited()
{
    QSettings settings;
    settings.setValue("settings/port", portLineEdit->text());
}
