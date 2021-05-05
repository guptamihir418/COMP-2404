// Mihir Gupta
// 101172281

#include <iostream>
#include <iomanip>
using namespace std;

#include "Reservation.h"

Reservation::Reservation(Guest* g, Room* r, Date* d, int stayingDays) 
    :reservationGuest(g), assignedRoom(r), arrivalDate(d), stay(stayingDays)
{
    totalCharge =  (assignedRoom->getRoomPrice()) * (float)stay;
}

Reservation::~Reservation(){
    delete arrivalDate;
}

// getter functions
int Reservation::getStay(){
    return stay;
}

Guest* Reservation::getReservedGuest(){
    return reservationGuest;
}

Room* Reservation::getReservedRoom(){
    return assignedRoom;
}

float Reservation::getTotalCharge(){
    return totalCharge;
}

Date* Reservation::getArrivaldate(){
    return arrivalDate;
}

bool Reservation::lessThan(Reservation* res){

    if(arrivalDate->lessThan(*res->arrivalDate)){
        return true;
    }
    return false;

}

void Reservation::print(){

    cout<<"-- GUEST: "      <<setw(7)  << left << reservationGuest->getName()<<";"
                            <<setw(13) << left << "  ROOM: "   <<assignedRoom->getRoomNum()<<";"
                            <<setw(5)  << left << "  ARRIVAL:  ";
                            arrivalDate->print();
                            cout<<setw(4)<<left;
    cout<<";"               <<setw(10)  << left << "  STAY: "    <<stay<<"; "<<setw(15)
                            <<setw(6)  << right << "    TOTAL:  $ " << totalCharge<<endl;
    
}