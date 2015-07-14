#ifndef __micro_voip_SIPTransportManager__
#define __micro_voip_SIPTransportManager__

#include "SIPTransport.h"
#include <string>
#include <map>


namespace micro {
namespace voip {


/**
 * SIP Transport management class.
 */
class SIPTransportManager {

    private :
        // TODO: use this...
        static std::map<int, SIPTransport*> transports;

        /** Private constructor. */
        SIPTransportManager();

    public :

        /** Creates transport. */
        static SIPTransport* createTransport(SIPTransport::TransportType type, int port = 5060);
};

}
}

#endif /* __micro_voip_SIPTransport__ */
