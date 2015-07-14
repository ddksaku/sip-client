#ifndef __micro_voip_SIPAccountManager__
#define __micro_voip_SIPAccountManager__

#include "SIPAccount.h"
#include <pjsua-lib/pjsua.h>
#include <QtCore/QString>
#include <map>



namespace micro {
namespace voip {

/**
 * SIP account manager.
 * Manages accounts.
 */
class SIPAccountManager {

	private :
        static SIPAccount *defaultAccount;  /**< Default account. */

        /** Private constructor with no implementation (i.e. no instances or subclasses). */
        SIPAccountManager();

	public :
        /** Adds account. */
        static SIPAccount* addAccount(const QString &accname, const QString &username, const QString &password, const QString &provider, bool isDefault);

        /** Adds local account. */
        static SIPAccount* addLocalAccount(SIPTransport *transport, bool isDefault);

        /** Removes account. */
        static void removeAccount(SIPAccount *account);

        /** Sets default account. */
        static void setDefaultAccount(SIPAccount *account);

        /** Returns default account. */
        static SIPAccount* getDefaultAccount() { return defaultAccount; }
};

}
}

#endif /* __micro_voip_SIPAccountManager__ */
