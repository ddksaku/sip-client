#include "SIPCall.h"
#include <pjsua-lib/pjsua.h>

using namespace micro::voip;

bool SIPCall::hangup()
{
    pj_status_t status = pjsua_call_hangup(id, 0, NULL, NULL);
    return (status == PJ_SUCCESS);
}

bool SIPCall::answer(int code)
{
    pj_status_t status = pjsua_call_answer(id, code, NULL, NULL);
}

void SIPCall::dialDTMF(const QString &digits)
{
    QByteArray byteArray = digits.toLatin1();
    pjsua_call_dial_dtmf(id, &pj_str(byteArray.data()));
}

QString SIPCall::getRemoteInfo() const
{
    pjsua_call_info info;
    pj_status_t status = pjsua_call_get_info(id, &info);
    if (status == PJ_SUCCESS) {
        return QString(pj_strbuf(&info.remote_info));
    }
    else {
        return "";
    }
}

QString SIPCall::getRemoteContact() const
{
    pjsua_call_info info;
    pjsua_call_get_info(id, &info);
    return QString(pj_strbuf(&info.remote_contact));
}
