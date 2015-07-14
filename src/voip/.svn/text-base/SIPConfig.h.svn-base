#ifndef __micro_voip_SIPConfig__
#define __micro_voip_SIPConfig__

#include <QtCore/QString>

namespace micro {
namespace voip {

/**
 * SIP Stack configuration.
 */
class SIPConfig {

    private :
        QString userAgent;      /**< User-Agent name. */
        QString stunServer;     /**< STUN server domain. */
        QString proxyServer;    /**< Proxy server. */
        QString proxyPort;      /**< Proxy port. */
        QString logFile;        /**< Log file. */

    public :

        /** Constructor. */
        SIPConfig() : userAgent("PJSIP based User-Agent"), stunServer(""), proxyServer(""), proxyPort(""), logFile("") {}

        /** Returns User-Agent name. */
        QString getUserAgent() const { return userAgent; }

        /** Sets User-Agent name. */
        void setUserAgent(const QString &userAgent) { this->userAgent = userAgent; }

        /** Returns STUN server domain. */
        QString getSTUNServer() const { return stunServer; }

        /** Sets STUN server domain. */
        void setSTUNServer(const QString &stunServer) { this->stunServer = stunServer; }

        /** Returns proxy server. */
        QString getProxyServer() const { return proxyServer; }

        /** Sets proxy server. */
        void setProxyServer(const QString &proxyServer) { this->proxyServer = proxyServer; }

        /** Returns proxy port. */
        QString getProxyPort() const { return proxyPort; }

        /** Sets proxy port. */
        void setProxyPort(const QString &proxyPort) { this->proxyPort = proxyPort; }

        /** Returns log file. */
        QString getLogFile() const { return logFile; }

        /** Sets log file. */
        void setLogFile(const QString &logFile) { this->logFile = logFile; }
};

}
}


#endif /* __micro_voip_SIPConfig__ */
