#include "SIPTransport.h"
#include <pjsua-lib/pjsua.h>

using micro::voip::SIPTransport;


SIPTransport::SIPTransport(int id) : id(id), closed(false), enabled(true)
{
}

SIPTransport::~SIPTransport()
{
    close(false);
}

void SIPTransport::close(bool force)
{
    if (!closed) {
        pj_status_t status;
        status = pjsua_transport_close(this->id, force);
        if (status == PJ_SUCCESS) {
            closed = true;
        }
    }
}

void SIPTransport::setEnable(bool enable)
{
    if (this->enabled != enable) {
        pj_status_t status;
        status = pjsua_transport_set_enable(this->id, enable);
        if (status == PJ_SUCCESS) {
            this->enabled = enable;
        }
    }
}
