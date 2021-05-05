// Mihir Gupta
// 101172281
#ifndef SHELTER_H
#define SHELTER_H

#include <string>
#include "Animal.h"
#include "Client.h"
#include "MatchListByClient.h"
#include "MatchListByScore.h"


class Shelter {

    public:
        Shelter(string="Name");
        ~Shelter();
        bool add(Animal*);
        bool add(Client*);
        void printAnimals();
        void printClients();
        void computeMatches(MatchListByScore&, MatchListByClient&);

    private:

        string name;
        Animal* animalsArr[MAX_SIZE];
        int numAnimal;
        Client* clientsArr[MAX_SIZE];
        int numClient;
        float calculateScore(Client*, Animal*);



};

#endif