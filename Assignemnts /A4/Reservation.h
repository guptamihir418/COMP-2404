// Mihir Gupta
// 101172281

#ifndef RESERVATION_H
#define RESERVATION_H

#include "Guest.h"
#include "Date.h"
#include "Room.h"

class Reservation{

    public:
        Reservation(Guest*, Room*, Date*, int);
        ~Reservation();
        bool lessThan(Reservation*);
        void print();
        int getStay();
        Guest* getReservedGuest();
        Room* getReservedRoom();
        float getTotalCharge();
        Date* getArrivaldate();

    private:
        Guest*   reservationGuest;
        Date*    arrivalDate;
        int      stay;  
        Room*    assignedRoom;
        float    totalCharge;

};

#endif