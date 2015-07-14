#ifndef __micro_voip_SIPAccount__
#define __micro_voip_SIPAccount__

#include "SIPTransport.h"
#include "SIPCall.h"
#include <pjsua-lib/pjsua.h>
#include <QtCore/QString>


namespace micro {
namespace voip {


// Declaration only (SIPStack and SIPAccountManager are friend classes)
class SIPStack;
class SIPAccountManager;


/**
 * SIP account.
 */
class SIPAccount {

        friend class SIPAccountManager;
        friend class SIPStack;

    private :

        int id;
        pjsua_acc_info info;
        pjsua_acc_config config;


    public :
        /** Destructor. */
        virtual ~SIPAccount();

        /** Returns account's identifier. */
        int getId() const { return id; }

        /** Returns URI of the account. */
        QString getURI();

        /** Returns true, if the account is online. */
        bool isOnline();

        /** Returns account's online status text. */
        QString getOnlineText();

        /** Sets online status. */
        bool setOnline(bool online);

        /** Tells whether the account has registration settings. */
        bool hasRegistration();

        /** Returns last registration status. */
        int getRegistrationStatus();

        /** Returns last registration status text. */
        QString getRegistrationStatusText();

        /** Locks/binds the account to specific transport. Normally not needed. */
        void setTransport(SIPTransport *transport);

        /** Makes a call from the account to URI specified by parameter. */
        SIPCall* makeCall(const QString &uri);


    private :
        /** Private constructor. Create accounts via addAccount method. */
        SIPAccount(int id);

        /* Gets info about the account from PJSUA library. */
        void refreshInfo();

};

}
}

#endif /* __micro_voip_SIPAccount__ */
