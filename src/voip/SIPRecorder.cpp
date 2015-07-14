#include "SIPRecorder.h"
#include <pjsua-lib/pjsua.h>

using namespace std;
using namespace micro::voip;

SIPRecorder::SIPRecorder(int id) : id(id)
{
}

SIPRecorder::~SIPRecorder()
{
    pjsua_recorder_destroy(id);
}

SIPRecorder* SIPRecorder::createRecorder(const std::string &file)
{
    int id;
    pj_status_t status = pjsua_recorder_create(&pj_str((char*)file.c_str()), 0, 0, 0, 0, &id);
    if (status == PJ_SUCCESS) {
        return new SIPRecorder(id);
    }
    else {
        return 0;
    }
}
