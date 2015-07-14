#include "SIPPlayer.h"
#include <pjsua-lib/pjsua.h>

using namespace std;
using namespace micro::voip;

SIPPlayer::SIPPlayer(int id) : id(id)
{
}

SIPPlayer::~SIPPlayer()
{
    pjsua_player_destroy(id);
}

SIPPlayer* SIPPlayer::createPlayer(const std::string &file)
{
    int id;
    pj_status_t status = pjsua_player_create(&pj_str((char*)file.c_str()), PJMEDIA_FILE_NO_LOOP, &id);
    if (status == PJ_SUCCESS) {
        return new SIPPlayer(id);
    }
    else {
        return 0;
    }
}

void SIPPlayer::setPlaybackPosition(unsigned int samples)
{
    pjsua_player_set_pos(id, samples);
}
