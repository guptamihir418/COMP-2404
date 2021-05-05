// Mihir Gupta
// 101172281

#ifndef TELCO_H
#define TELCO_H

#include "Subscriber.h"
#include "Call.h"
#include "Array.h"

class Telco {

    public:
    Telco(string="", int=0);

    ~Telco();

    void addSub(Subscriber*);
    void addCall(string, string, 
                int, int, int,
                int, int, int);
    
    void computeFreqCaller(string);
    void computeFreqCalled(string);
    void print();





    private:
    string name;
    int numSubs;
    Array CallsArr;

    Subscriber* subsArr[MAX_ARR];

    // helper funcs
    int sourceIndex(string);
    int destIndex(string);
    int NumExists(string, string[], int);

    int getHighestNum(int[], int);



};

#endif