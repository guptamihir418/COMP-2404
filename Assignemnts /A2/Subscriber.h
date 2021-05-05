// Mihir Gupta
// 101172281

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Call.h"
#include "Array.h"




class Subscriber {

    public:
        Subscriber(string="");

        ~Subscriber();
        void addIncoming(Call*);
        void addOutgoing(Call*);
        void print();

        string getPhoneNum();
        Array* getInCallArr();
        Array* getOutCallArr();
    
    private:
        Array incomingArr;
        Array outgoingArr;
        string phoneNum;



};

#endif
