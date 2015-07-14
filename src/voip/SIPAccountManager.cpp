#include "SIPAccountManager.h"
#include <iostream>
#include <sstream>
using namespace std;

using namespace micro::voip;

SIPAccount* SIPAccountManager::defaultAccount = 0;

SIPAccount* SIPAccountManager::addAccount(const QString &accname, const QString &username, const QString &password, const QString &provider, bool isDefault)
{
    QByteArray ba;

    // Fill configuration structure
    pjsua_acc_config config;
    pjsua_acc_config_default(&config);

    QString string("sip:" + username + "@" + provider);
    ba = string.toLatin1();
    config.id = pj_str(ba.data());
    config.reg_uri = pj_str(ba.data());
    config.cred_count = 1;
    ba = username.toLatin1();
    config.cred_info[0].username = pj_str(ba.data());
    config.cred_info[0].realm = pj_str("*");
    config.cred_info[0].scheme = pj_str("digest");
    config.cred_info[0].data_type = PJSIP_CRED_DATA_PLAIN_PASSWD;
    ba = password.toLatin1();
    config.cred_info[0].data = pj_str(ba.data());
    
    pjsua_acc_id id;
    pj_status_t status;
    status = pjsua_acc_add(&config, isDefault, &id);

    if (status == PJ_SUCCESS) {
        SIPAccount *account = new SIPAccount((int)id);  // Create account object
        if (isDefault) {
            defaultAccount = account;
        }
        return account;
    }
    else {
        pjsua_perror("SIPAccountManager", "creating account failed", status);
        return 0;
    }
}

SIPAccount* SIPAccountManager::addLocalAccount(SIPTransport *transport, bool isDefault)
{   
    pjsua_acc_id id;
    pj_status_t status;
    status = pjsua_acc_add_local(transport->getId(), isDefault, &id);

    if (status == PJ_SUCCESS) {
        SIPAccount *account = new SIPAccount((int)id);  // Create account object
        if (isDefault) {
            defaultAccount = account;
        }
        return account;
    }
    else {
        pjsua_perror("SIPAccountManager", "creating local account failed", status);
        return 0;
    }
}


void SIPAccountManager::removeAccount(SIPAccount *account)
{
    if (account == 0 || account->id == -1)
        return;

    pjsua_acc_del(account->id);        // Delete account from SIP server
    if (defaultAccount == account) {
        defaultAccount = 0;
    }

    account->id = -1;
}

void SIPAccountManager::setDefaultAccount(SIPAccount *account)
{
    pjsua_acc_set_default(account->getId());
    defaultAccount = account;
}
