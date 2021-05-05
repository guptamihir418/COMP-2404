// Mihir Gupta
// 101172281

#ifndef RECORDER_H
#define RECORDER_H

#include <string>

#include "Reservation.h"

class Recorder {

    public:
        Recorder(string="name");
        virtual ~Recorder();
        void printRecords();
        virtual void update(Reservation*) = 0; // pure virtual and abstract class


    protected:
        string recorderName;
        vector <string> recordsColl;

};

#endif