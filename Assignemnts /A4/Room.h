// Mihir Gupta
// 101172281

#ifndef ROOM_H
#define ROOM_H

#include "defs.h"
#include <string>


class Room{

    public:

        Room(ReqRoomType = C_REG, int=0, float=0.0);
        int getRoomNum();
        float getRoomPrice();
        string getRoomType();
        void print();
        void computePoints(int& pts);
        
        
    private:
        
        ReqRoomType room;
        int         roomNum;
        float       price;

};

#endif