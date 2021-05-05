// Mihir Gupta
// 101172281

#include <iostream>
#include <string>
using namespace std;

#include "Call.h"

//Call(string="", string="", int=0, -> calls
        //int=0, int=0, int=2000, -> date
        //int=0, int=0); -> time

Call::Call (string s, string des, int dur, 
                int d, int m, int y,
                int h, int min)

    : src(s), dest(des), duration(dur)

{
    startDate = new Date(d,m,y);
    startTime = new Time(h, min);
    // cout<< "ctor of call....."<<endl;

}

// destructor
Call::~Call(){

    cout<<"-- Student dtor:  "<<endl;
    delete startDate;
    delete startTime;
}

// checks if the call is greather than the other call
bool Call::greaterThan(Call* c){

    // comparison for dates
    if(startDate->greaterThan(c->startDate)){
        return true;
    }

    // if dates are equal
    else if(startDate->equals(c->startDate)){

    // comparison for time
        if(startTime->greaterThan(c->startTime)){
            return true;
        }
    }
    return false;
}

// prints the call in fancy manner
void Call::print(){

    cout<< "Source: " << src << endl;
    cout<< "Destination: " << dest << endl;

    cout<< "Date Started: ";
    startDate->print();

    cout<< "Time Started: ";
    startTime->print();
    cout << endl;

    cout<< "Duration: " << duration <<" Minutes"<< endl;
}

// gives the source phone number
string Call::getSrcNum(){
    return src;
}

// gives the destination phone number
string Call::getDestNum(){
    return dest;
}