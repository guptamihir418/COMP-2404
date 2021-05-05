// Mihir Gupta
// 101172281

#include <iostream>
using namespace std;
#include <sstream>

#include "UpgradeRecorder.h"


UpgradeRecorder::UpgradeRecorder(string n)
    : Recorder(n)
    { }

// UpgradeRecorder::~UpgradeRecorder(){ }

void UpgradeRecorder::update(Reservation* res){

    if(res->getReservedGuest()->getPremium() == false){

        if(res->getTotalCharge() > 1500.0){

            stringstream temp;

            temp<< res->getReservedGuest()->getName()<<",   "<<"$ "<< res->getTotalCharge();
            string final = temp.str();
            
            recordsColl.push_back(final);
        }
    }
}