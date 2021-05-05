// Mihir Gupta
// 101172281
#ifndef MATCH_H
#define MATCH_H

#include "Animal.h"
#include "Client.h"

class Match {

    public:

        Match(Animal*, Client*, float=0);
        ~Match();
        float getScore();
        string getClientID();
        void print();

    protected:

    private:
        Animal* animalInvolved;
        Client* clientInvolved;

        float score;

};

#endif