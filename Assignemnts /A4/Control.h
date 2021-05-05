// Mihir Gupta
// 101172281

#ifndef CONTROL_H
#define CONTROL_H

#include "ResManager.h"
#include "View.h"
#include "Hotel.h"
#include "StayRecorder.h"
#include "GuestRecorder.h"
#include "UpgradeRecorder.h"

class Control
{
    public:
        Control();
        ~Control();
        void launch();

    private:
        void         initHotel();
        ResManager*  resMgr;
        Hotel*       hotel;
        View         v;

};

#endif
