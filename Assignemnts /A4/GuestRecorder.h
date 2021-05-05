// Mihir Gupta
// 101172281

#ifndef GUESTRECORDER_H
#define GUESTRECORDER_H

#include <string>
#include <vector>

#include "Recorder.h"

class GuestRecorder : public Recorder
{
    public:
        GuestRecorder(string="Name");
        virtual void update(Reservation*);
        // ~GuestRecorder();

};

#endif