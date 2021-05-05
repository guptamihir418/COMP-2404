// Mihir Gupta
// 101172281

#ifndef HOTEL_H
#define HOTEL_H

#define MAX_ARR  256

#include <string>
#include "Guest.h"
#include "RoomArray.h"

class ResManager;

class Hotel{
    public:
        Hotel(string, ResManager*);
        ~Hotel();
        void addGuest(Guest*);
        void addRoom(Room*);
        void printGuests();
        void printRooms();
        bool findGuest(string n, Guest** g);
        RoomArray* getRoomsArr();


    private:
        string       name;
        Guest*       GuestArr[MAX_ARR];
        int          numGuests;
        RoomArray    rooms;
        ResManager*  manager;

};

#endif