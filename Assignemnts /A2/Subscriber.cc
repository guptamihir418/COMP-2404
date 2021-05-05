// Mihir Gupta
// 101172281

#include <iostream>
#include <string>

using namespace std;

#include "Subscriber.h"



Subscriber::Subscriber(string phone)
    : phoneNum(phone)

{
    // cout<<"inside subscirber ctor...."<<endl;


}

Subscriber::~Subscriber(){

    // incomingArr.cleanup();
    // outgoingArr.cleanup();
}

void Subscriber::addIncoming(Call* c){
    incomingArr.add(c);
}

void Subscriber::addOutgoing(Call* c){
    outgoingArr.add(c);
}

void Subscriber::print(){


    Array tempArr(incomingArr); //copying

    // adding other calls to this array
    tempArr.add(outgoingArr);

    cout<<"SUBSCRIBER's Phone Number: "<<phoneNum<<endl;
    cout<<"SUBSCRIBER's Combined Calls"<<endl;
    tempArr.print();
}

// getter to return phone number of teh subscriber
string Subscriber::getPhoneNum(){
    return phoneNum;
}

// getter function returns incoming array
Array* Subscriber::getInCallArr(){
    return &incomingArr;
}

// getter function returns outgoing array
Array* Subscriber::getOutCallArr(){
    return &outgoingArr;
}