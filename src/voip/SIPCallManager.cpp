#include "SIPCallManager.h"
#include <pjsua-lib/pjsua.h>

using namespace micro::voip;

SIPCall* SIPCallManager::makeCall(SIPAccount *account, const QString &uri)
{
    int id = 0;
    pj_status_t status = -1;
    QByteArray byteArray = uri.toLatin1();
    pj_str_t callURI = pj_str(byteArray.data());
    status = pjsua_call_make_call(account->getId(), &callURI, 0, NULL, NULL, &id);

    if (status == PJ_SUCCESS) {
        return new SIPCall(id);
    }

    return 0;
}


void SIPCallManager::hangupAll()
{
    pjsua_call_hangup_all();
}
