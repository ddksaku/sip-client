#ifndef __micro_voip_SIPCallManager__
#define __micro_voip_SIPCallManager__

#include "SIPAccount.h"
#include "SIPCall.h"
#include <QtCore/QString>
#include <map>


namespace micro {
namespace voip {


/**
 * SIP Call management class.
 */
class SIPCallManager {

    private :

        /** Private constructor. */
        SIPCallManager();

    public :

        /** Makes a SIP call. */
        static SIPCall* makeCall(SIPAccount *account, const QString &uri);

        /** Hangups all calls. */
        static void hangupAll();
};

}
}

#endif /* __micro_voip_SIPCallManager__ */
