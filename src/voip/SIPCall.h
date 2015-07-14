#ifndef __micro_voip_SIPCall__
#define __micro_voip_SIPCall__

#include <QtCore/QString>
#include <pjsua-lib/pjsua.h>



namespace micro {
namespace voip {

// Declaration only
class SIPCallManager;

/**
 * SIP Call.
 */
class SIPCall {

    public :
        enum SIPCallState {
            STATE_NULL = PJSIP_INV_STATE_NULL,
            STATE_CALLING = PJSIP_INV_STATE_CALLING,
            STATE_INCOMING = PJSIP_INV_STATE_INCOMING,
            STATE_EARLY = PJSIP_INV_STATE_EARLY,
            STATE_CONNECTING = PJSIP_INV_STATE_CONNECTING,
            STATE_CONFIRMED = PJSIP_INV_STATE_CONFIRMED,
            STATE_DISCONNECTED = PJSIP_INV_STATE_DISCONNECTED
        };

    private :

        friend class SIPCallManager;

        int id; /**< Call ID. */

    public :

        /** Constructor. */
        SIPCall(int id) : id(id) {}

        /** Returns call ID. */
        int getId() const { return id; }

        /** Returns true, if call is active. */
        bool isActive() const;

        /** Answers the call. */
        bool answer(int code = 200);

        /** Hangups the call. */
        bool hangup();

        /** Send DTMF digits to remote. */
        void dialDTMF(const QString &digits);

        /** Returns remote URL. */
        QString getRemoteInfo() const;

        /** Returns remote contact. */
        QString getRemoteContact() const;
};

}
}

#endif /* __micro_voip_SIPCall__ */
