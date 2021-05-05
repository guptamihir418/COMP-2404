// Mihir Gupta
// 101172281

#ifndef RESMANAGER_H
#define RESMANAGER_H

#include <vector>

#include "Hotel.h"
#include "Reservation.h"
#include "Recorder.h"

class Hotel;

class ResManager{

    public:
        ResManager(Hotel* = NULL);
        ~ResManager();
        void setHotel(Hotel*);
        void addReservation(string name, int yr, int mth, int day, int stay, ReqRoomType req);
        void subscribe(Recorder*);
        void print();
        void printRecords();


    private:
        Hotel* managedHotel;
        Reservation* resHotels[MAX_ARR];
        int resHotelSize;
        vector <Recorder*> eventRecorders;
        void notify(Reservation*);
        Room* roomAvailability(int, Date*, int);
        void add(Reservation*);


};

#endif