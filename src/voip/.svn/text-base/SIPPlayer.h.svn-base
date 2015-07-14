#ifndef __micro_voip_SIPPlayer__
#define __micro_voip_SIPPlayer__

#include <string>


namespace micro {
namespace voip {


/**
 * SIP Player.
 */
class SIPPlayer {

    private :
        int id; /**< Player ID. */

        /** Private constructor. (to create instance use createPlayer) */
        SIPPlayer(int id);

    public :
        
        /** Creates instance of SIPPlayer class. */
        static SIPPlayer* createPlayer(const std::string &file);

        /** Destructor. */
        ~SIPPlayer();

        /** Returns player ID. */
        int getId() { return id; }

        /** Sets playback position in samples. 0 to re-start the playback. */
        void setPlaybackPosition(unsigned int samples);

        // TODO:
        //SIPPort getPort();

        // ???
        //SIPMediaPort getMediaPort();


        
};

}
}

#endif /* __micro_voip_SIPPlayer__ */
