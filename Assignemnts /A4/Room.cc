// Mihir Gupta
// 101172281

#include <iostream>
#include <iomanip>
using namespace std;

#include "Room.h"

Room::Room(ReqRoomType r, int num, float rate)
    : room(r),roomNum(num), price(rate)
{ }

int Room::getRoomNum(){
    return roomNum;
}

float Room::getRoomPrice(){
    return price;
}

string Room::getRoomType(){

    if (room == C_REG){
        return "Regular";
    }
    else if (room == C_PREM){
        return "Premium";
    }
    if (room == C_SUITE){
        return "Suite";
    }
    return "";
}

void Room::print(){

    cout<<"-- "     <<setw(7) << left << roomNum
                    <<setw(13) << left << this->getRoomType()
                    <<setw(1)  << left <<"Room:   $ "<< price<< "  per night"<<endl;

}       

void Room::computePoints(int& pts){

    if(room == C_SUITE){           //means suite
        pts = price/5.0;
    }
    else if(room == C_PREM){       // means premium
        pts = (price*3.0)/20.0;
    }
    else if( room == C_REG){       // regular
        pts = price/10.0;
    }
}