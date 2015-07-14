#include "SIPAccount.h"
#include "SIPAccountManager.h"
#include "../logging/Logger.h"

using namespace micro::voip;


SIPAccount::SIPAccount(int id) : id(id)
{
}


SIPAccount::~SIPAccount()
{
}


void SIPAccount::refreshInfo()
{
    pjsua_acc_get_info(id, &info);
}


QString SIPAccount::getURI()
{
    refreshInfo();
    pj_str_t uri = info.acc_uri;
    return QString(pj_strbuf(&uri));
}


bool SIPAccount::isOnline()
{
    refreshInfo();
    return (info.online_status == PJ_TRUE);
}


QString SIPAccount::getOnlineText()
{
    refreshInfo();
    pj_str_t text = info.online_status_text;
    return QString(pj_strbuf(&text));
}


bool SIPAccount::setOnline(bool online)
{
    return (pjsua_acc_set_online_status(id, online) == PJ_SUCCESS);
}


bool SIPAccount::hasRegistration()
{
    refreshInfo();
    return (info.has_registration == PJ_TRUE);
}


int SIPAccount::getRegistrationStatus()
{
    refreshInfo();
    return info.status;
}


QString SIPAccount::getRegistrationStatusText()
{
    refreshInfo();
    pj_str_t text = info.status_text;
    return QString(pj_strbuf(&text));
}


void SIPAccount::setTransport(SIPTransport *transport)
{
    pjsua_acc_set_transport(id, transport->getId());
}
