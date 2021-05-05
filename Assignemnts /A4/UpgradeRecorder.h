// Mihir Gupta
// 101172281

#ifndef UPGRADERECORDER_H
#define UPGRADERECORDER_H

#include <string>
#include <vector>

#include "Recorder.h"

class UpgradeRecorder : public Recorder
{
    public:
        UpgradeRecorder(string="Name");
        virtual void update(Reservation*);
        // ~UpgradeRecorder();

};

#endif