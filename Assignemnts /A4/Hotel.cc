// Mihir Gupta
// 101172281

#include <iostream>
using namespace std;
#define MAX_ARR  256

#include "Hotel.h"
#include "ResManager.h"

Hotel::Hotel(string n, ResManager* m) 
    :name(n), manager(m)
    {
        numGuests = 0;
    }

Hotel::~Hotel(){
    for (int i = 0; i < numGuests; ++i){
        delete GuestArr[i];
    }
}

RoomArray* Hotel::getRoomsArr(){
    return &rooms;
}

void Hotel::addGuest(Guest* g){


    if(numGuests >= MAX_ARR){
        cout<<"ERROR"<<endl;
        return;
    }
    GuestArr[numGuests] = g;
    ++numGuests;
}

void Hotel::addRoom(Room* r){
    rooms.add(r);
}

void Hotel::printGuests(){
    
    cout<<endl<<"GUESTS: "<<endl;

    for(int i = 0; i < numGuests; ++i){
        GuestArr[i]->print();
        cout<<endl;
    }
}
void Hotel::printRooms(){

    cout<<endl<<"ROOMS: "<<endl;
    rooms.print();
}

bool Hotel::findGuest(string n, Guest** g){

    for( int i = 0; i < numGuests; ++i){
        if(n == GuestArr[i]->getName()){
            *g = GuestArr[i];  
            return true;
        }
    }
    return false;
}