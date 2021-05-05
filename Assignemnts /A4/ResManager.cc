// Mihir Gupta
// 101172281

#include <iostream>
using namespace std;

#include "ResManager.h"

ResManager::ResManager(Hotel* h)
    : managedHotel(h)

{
    resHotelSize = 0;
}

ResManager:: ~ResManager(){

    for (int i = 0; i < resHotelSize; ++i){ 
        delete resHotels[i]; 
    }

    for (int i = 0; i < eventRecorders.size(); ++i){
        delete eventRecorders[i]; 
    }

}

void ResManager::setHotel(Hotel* h){
    managedHotel = h;

}

void ResManager::notify(Reservation* r){
    for (int i = 0; i < eventRecorders.size(); ++i){
        eventRecorders[i]->update(r);
    }
}

// function checks the availability of the  room
Room* ResManager::roomAvailability(int prevLoopIndex, Date* toAdd, int stay){

    //Loops through all the reservations in the hotel
    for (int i = 0; i < resHotelSize; ++i){

        // if condition checks the exact room if available or not
        if (resHotels[i]->getReservedRoom()->getRoomNum() 
                                    == managedHotel->getRoomsArr()->get(prevLoopIndex)->getRoomNum()){

            Date alreadyReserved(*(resHotels[i]->getArrivaldate())); //already reserved arrival date

            // suppose reservation exists for 23rd - 26th of any month

            // iterating over each day in reservation date till duration of its stay
            for (int j = 0; j < resHotels[i]->getStay(); ++j){
                
                Date toBeReserved(*toAdd);  // reservation to be made arrival date copy

                //suppose reservation is to be added for 21st - 24th of same month

                // this nested loops will compare 21st to 23,24,25,26
                // if its not equal we will increment one and move on to 22nd
                // and if any date is equal to any other date in the given durations it will return null

                // Checks for the dates
                for (int a = 0; a < stay; ++a){
                    if (alreadyReserved.equals(toBeReserved)){
                        return 0;
                    }
                    toBeReserved.add(1);
                }
                alreadyReserved.add(1);
            }
        }
    }
    // returning the found room
    return managedHotel->getRoomsArr()->get(prevLoopIndex);
}

// this function adds reservation in the ascending order 
// this is same function from my previous assignment for dates
void ResManager::add(Reservation* r){

    Reservation* temp1;
    Reservation* temp2;
    bool check;
    
    // error checking
    if(resHotelSize >= MAX_ARR){
        cout << "ERROR: NO MORE ITEMS CAN BE ADDED" <<endl;
        return;
    }

    // base case -> if array is empty
    if (resHotelSize == 0){
        resHotels[0] = r;
        ++resHotelSize;
        return;
    }

    else{
        for (int i = 0; i < resHotelSize; ++i){
            // comparing reservation
            if (r->lessThan(resHotels[i])){

                temp1 = resHotels[i];
                resHotels[i] = r;

                for (int j = i; j < resHotelSize; ++j){
                    
                    // array shifting 
                    temp2 = resHotels[j+1];
                    resHotels[j+1] = temp1;
                    temp1 = temp2;
                }
                check = false;
                ++resHotelSize;
                return;
            }
            else{
                check = true;
            }
        }
        // if adding at the last
        if (check == true){
            resHotels[resHotelSize] = r;
            ++resHotelSize;
            return;
        }
    }
}

// adds the reservation in the array
void ResManager::addReservation(string name, int yr, int mth, int day, int stay, ReqRoomType req){

    // stores the string version of "req"
    string reqString;

    // converts reqtype into string so that I can compare easily
    if(req == C_SUITE){
        reqString = "Suite";
    }
    else if(req == C_PREM){
        reqString = "Premium";
    }
    else if(req == C_REG){
        reqString = "Regular";
    }

    // error handling
    if (stay > 31 || stay < 0){
        cout <<"INVALID STAY" << endl;
        return;
    }

    // arrival date,room,guest that we are trying to make reservation for
    Date* dateToAdd  = new Date(day, mth, yr);
    Room* roomToAdd;
    Guest* guestToAdd;
    bool flag = true;

    //Need to find the first room that fits the criteria
    for (int i = 0; i < managedHotel->getRoomsArr()->getSize(); ++i){ 

        //Checks for room type match
        if ((managedHotel->getRoomsArr()->get(i)->getRoomType() == reqString)){

            roomToAdd = roomAvailability(i, dateToAdd, stay);
            if (roomToAdd != 0){

                flag = false;
                // breaks out of the if condition
                break;
            }
        }

        // break out of the forloop 
        if (flag == false){
            break;
            }
    }
    if (roomToAdd == 0){

        cout << "ERROR: Registration request for " << name << ", ";
        dateToAdd->print();
        cout << ":   No room of matching type available." << endl;
        // free the allocated memory
        delete dateToAdd;
        return;

    }

    // finding guest and saving it in the variable
    bool guestFound = managedHotel->findGuest(name, &guestToAdd);

    if(guestFound == false){
        cout << "ERROR: Guest " << name << " does not exist." << endl;
        // free the allocated memory
        delete dateToAdd;
        return;
    }

    // finally making the reservation
    // I have room, date and guest at this point
    Reservation* res = new Reservation(guestToAdd, roomToAdd, dateToAdd, stay);

    // adding the points
    int points;
    res->getReservedRoom()->computePoints(points);
    points *= res->getStay();
    res->getReservedGuest()->addPts(points);

    // adding the reservation according to the ascending order
    add(res);
    // notifying 
    notify(res);
}

void ResManager::subscribe(Recorder* r){
    eventRecorders.push_back(r);
}

void ResManager::print(){
    for(int i =0; i<resHotelSize; ++i){
        resHotels[i]->print();
    }
}

void ResManager::printRecords(){
    cout<<endl<<"EVENT RECORDS: "<<endl<<endl; 
    for(int i = 0; i < eventRecorders.size(); ++i){
        eventRecorders[i]->printRecords();
    }
}
