// Mihir Gupta
// 101172281

#include <iostream>
using namespace std;
#include <sstream>

#include "GuestRecorder.h"


GuestRecorder::GuestRecorder(string n)
    : Recorder(n)
    { }

// GuestRecorder::~GuestRecorder(){ }

void GuestRecorder::update(Reservation* res){

    Room* roomAllotted = res->getReservedRoom();

    if(res->getReservedGuest()->getPremium() == false){

        if( (roomAllotted->getRoomType() == "Premium") || 
        (roomAllotted->getRoomType() == "Suite") ){

            stringstream temp;

            temp<< " Premium Guest offer for "<< res->getReservedGuest()->getName();
            string final = temp.str();

            recordsColl.push_back(final);
        }
    }
}