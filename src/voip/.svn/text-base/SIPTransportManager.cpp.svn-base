#include "SIPTransportManager.h"
#include <pjsua-lib/pjsua.h>

using namespace micro::voip;


SIPTransport* SIPTransportManager::createTransport(SIPTransport::TransportType type, int port)
{
    int id = 0;
    pjsua_transport_config config;
    pjsua_transport_config_default(&config);
    config.port = port;

    pj_status_t status;
    pjsip_transport_type_e pjsipType;
    switch (type) {
        case SIPTransport::TRANSPORT_TCP :
            pjsipType = PJSIP_TRANSPORT_TCP;
            break;
        case SIPTransport::TRANSPORT_TCP6 :
            pjsipType = PJSIP_TRANSPORT_TCP6;
            break;
        case SIPTransport::TRANSPORT_UDP :
            pjsipType = PJSIP_TRANSPORT_UDP;
            break;
        case SIPTransport::TRANSPORT_UDP6 :
            pjsipType = PJSIP_TRANSPORT_UDP6;
            break;
        default :
            pjsipType = PJSIP_TRANSPORT_UNSPECIFIED;
    }

    status = pjsua_transport_create(pjsipType, &config, &id);

    return new SIPTransport(id);
}
