// Mihir Gupta
// 101172281

#ifndef CALL_H
#define CALL_H

#include "Date.h"
#include "Time.h"

class Call {

    public:
        Call(string="", string="", int=0, 
        int=0, int=0, int=2000,
        int=0, int=0);

        ~Call();

        bool greaterThan(Call*);
        void print();

        string getSrcNum();
        string getDestNum();


    private:
        string src;
        string dest;
        int duration;

        Date* startDate;
        Time* startTime;


};

#endif