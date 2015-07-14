#ifndef __micro_voip_SIPRecorder__
#define __micro_voip_SIPRecorder__

#include <string>


namespace micro {
namespace voip {


/**
 * SIP Recorder.
 */
class SIPRecorder {

    private :
        int id; /**< Recorder ID. */

        /** Private constructor. (to create instance use createRecorder) */
        SIPRecorder(int id);

    public :
        
        /** Creates instance of SIPRecorder class. */
        static SIPRecorder* createRecorder(const std::string &file);

        /** Destructor. */
        ~SIPRecorder();

        /** Returns recorder ID. */
        int getId() { return id; }

        // TODO:
        //SIPConferencePort getConferencePort();

        // ???
        //SIPMediaPort getMediaPort();


        
};

}
}

#endif /* __micro_voip_SIPRecorder__ */
