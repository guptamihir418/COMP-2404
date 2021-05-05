// Mihir Gupta
// 101172281

#ifndef STAYRECORDER_H
#define STAYRECORDER_H

#include <string>
#include <vector>

#include "Recorder.h"

class StayRecorder : public Recorder
{
    public:
        StayRecorder(string="Name");
        virtual void update(Reservation*);
        // ~StayRecorder();

};

#endif