// Mihir Gupta
// 101172281

#ifndef AGENDA_H
#define AGENDA_H

#include "Calendar.h"

class Agenda{

    public:
        Agenda(string = "Agenda");
        ~Agenda();
        bool add(Calendar*);
        bool find(string, Calendar**);
        bool add(Date*, string);
        void print();


    private:
        string agendaName;
        int currentCals;
        Calendar** CalsArr;



};

#endif
