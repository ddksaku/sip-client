#ifndef __Network__
#define	__Network__

#include <QString>

/**
 * Network settings.
 */
class Network {

    private :
        bool useProxy;
        QString proxy;
        QString port;
        
        bool useStun;
        QString stun;
        
    public :
        
        /** Constructor */
        Network()
        {}
        
        /** Returns use proxy flag. */
        bool getUseProxy() { return useProxy; }
        
        /** Sets use proxy flag. */
        void setUseProxy(bool proxy) { this->useProxy = proxy; }
        
        /** Returns proxy. */
        QString getProxy() { return proxy; }
        
        /** Sets proxy. */
        void setProxy(const QString &proxy) { this->proxy = proxy; }
        
        /** Returns proxy port. */
        QString getPort() { return port; }
        
        /** Sets proxy port. */
        void setPort(const QString &port) { this->port = port; }
        
        /** Returns use STUN flag. */
        bool getUseSTUN() { return useStun; }
        
        /** Sets use STUN flag. */
        void setUseSTUN(bool useStun) { this->useStun = useStun; }
        
        /** Returns STUN server. */
        QString getSTUN() { return stun; }
        
        /** Sets STUN server. */
        void setSTUN(const QString &stun) { this->stun = stun; }
        
};

#endif	/* __Network__ */
