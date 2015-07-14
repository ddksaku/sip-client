#ifndef __micro_voip_SIPStackListener__
#define	__micro_voip_SIPStackListener__

#include "SIPCall.h"
#include "SIPAccount.h"

namespace micro {
namespace voip {
    
/**
 * SIP Stack event listener.
 */
class SIPStackListener {
        
    public :
        virtual void onCallState(SIPCall &sipCall, int callState) = 0;
        virtual void onRegistrationState(SIPAccount &sipAccount, int registrationCode, int onlineState) = 0;
        virtual void onIncomingCall(SIPCall &sipCall) = 0;
        
};

}
}

#endif	/* __SIPStackListener__ */
