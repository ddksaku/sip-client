#ifndef __micro_voip_SIPStack__
#define __micro_voip_SIPStack__

#include "SIPConfig.h"
#include "SIPTransport.h"
#include "SIPStackListener.h"
#include "../logging/Logger.h"
#include <pjsua-lib/pjsua.h>
#include <QtCore/QString>


using namespace micro::logging;

namespace micro {
namespace voip {

/**
 * SIP Stack.
 */
class SIPStack {

    private :
        static SIPTransport *transport;    /**< SIP transport. */

        static SIPStackListener *listener;  /**< SIP Stack event listener. */

        /** Private constructor with no implementation (i.e. no instances of this class). */
        SIPStack();

    public :
        /** Creates SIP Stack. */
        static bool create();

        /** Initializes SIP Stack. Method create() must be call before calling this method. */
        static bool init(const SIPConfig &configuration);

        /** Destroys SIP Stack. */
        static void destroy();

        /** Detects NAT type. */
        static void detectNATType();

        /** Returns NAT type. */
        static int getNATType();

        /** Verifies SIP URL. */
        static bool verifyURL(const QString &url);

        static void setListener(SIPStackListener *listener) { SIPStack::listener = listener; }

    private :
        static void onRegistrationState(pjsua_acc_id accountId);
        static void onIncomingCall(pjsua_acc_id accountId, pjsua_call_id callId, pjsip_rx_data *rxData);
        static void onCallState(pjsua_call_id callId, pjsip_event *e);
        static void onCallMediaState(pjsua_call_id callId);


        static void onStreamCreated(pjsua_call_id callId, pjmedia_session *session, unsigned streamIdx, pjmedia_port **pPort);
};

}
}

#endif /* __micro_voip_SIPStack__ */
