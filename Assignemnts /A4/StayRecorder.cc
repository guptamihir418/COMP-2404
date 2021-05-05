// Mihir Gupta
// 101172281

#include <iostream>
using namespace std;
#include <sstream>

#include "StayRecorder.h"


StayRecorder::StayRecorder(string n)
    : Recorder(n)
    { }

// StayRecorder::~StayRecorder(){ }

void StayRecorder::update(Reservation* res){

    if(res->getStay() > 3){

        stringstream temp;

        temp<< res->getReservedGuest()->getName()<<",   "<< res->getStay()<<" Nights";
        string final = temp.str();

        recordsColl.push_back(final);
    }
}