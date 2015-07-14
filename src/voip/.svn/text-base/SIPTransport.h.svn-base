#ifndef __micro_voip_SIPTransport__
#define __micro_voip_SIPTransport__


namespace micro {
namespace voip {

// Declaration only.
class SIPTransportManager;


/**
 * SIP Transport.
 */
class SIPTransport {

        friend class SIPTransportManager;

    public :
        /** Transport type enum. */
        enum TransportType {
            TRANSPORT_UDP,      /**< UDP. */
            TRANSPORT_TCP,      /**< TCP. */
            TRANSPORT_UDP6,     /**< UDP over IPv6. */
            TRANSPORT_TCP6      /**< UDP over IPv6. */
        };
    
    private :
        int id;             /**< Transport identification. */
        bool closed;        /**< Closed flag. */
        bool enabled;       /**< Enabled flag. */

        /** Private constructor. To create the instance use SIPTransportManager::createTransport method. */
        SIPTransport(int id);

    public :

        /** Destructor. */
        virtual ~SIPTransport();


        /** Returns the transport identificator. */
        int getId() const { return id; }

        /** Closes transport. */
        void close(bool force);

        /** Enables/disables the trasport. */
        void setEnable(bool enable);

        /** Returns true if the trasport is enabled or false if the trasport is disabled. */
        bool isEnable() const { return enabled; }
};

}
}

#endif /* __micro_voip_SIPTransport__ */
