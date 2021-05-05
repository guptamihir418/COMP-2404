// Mihir Gupta
// 101172281
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

#include "Shelter.h"
#define MAX_SIZE 128


Shelter::Shelter(string n)
    :name(n)
    {
        numAnimal = 0;
        numClient = 0;
    }

// deallocates the memory
Shelter::~Shelter(){

    for(int i = 0; i<numClient; ++i){
        delete clientsArr[i];
    }
    for(int i = 0; i<numAnimal; ++i){
        delete animalsArr[i];
    }


}
// adds animal to the end of the list
bool Shelter::add(Animal* a){

    if(numAnimal >= MAX_SIZE){
        return false;
    }
    animalsArr[numAnimal] = a;
    ++numAnimal;
    return true;
}

// adds Client to the end of the list
bool Shelter::add(Client* c){

    if(numClient >= MAX_SIZE){
        return false;
    }
    clientsArr[numClient] = c;
    ++numClient;
    return true;
}
// print animals
void Shelter::printAnimals(){

    cout<<"ANIMALS: "<<endl;
    for(int i = 0; i < numAnimal; ++i){
        animalsArr[i]->print();
    }
}

// print clients
void Shelter::printClients(){

    cout<<"CLIENTS: "<<endl;
    for(int i = 0; i < numClient; ++i){
        clientsArr[i]->print();
    }
}

// helper function -> calculates the score of match between client and an animal
float Shelter::calculateScore(Client* c, Animal* a){

    // storing size in a variable so that get functions are not called everytime
    int sizeOfCriArr = c->getCriteriaArr()->getSize();
    CriteriaArray* mainArr = c->getCriteriaArr();

    float score;
    score = 0.0f;

    for(int i =0; i < sizeOfCriArr; ++i){

            // if species -> add 10 to the score
            if(mainArr->get(i)->getName() == "Species"){
                if(mainArr->get(i)->getValue() == a->getSpecies()){
                    score = score + 10.0;
                }
            }

            // if breed -> add weight to the score
            if(mainArr->get(i)->getName() == "Breed"){
                if(mainArr->get(i)->getValue() == a->getBreed()){
                    score = score + (float)mainArr->get(i)->getWeight();
                }
            }
            // if gender -> add weight to the score
            if(mainArr->get(i)->getName() == "Gender"){
                if(mainArr->get(i)->getValue() == a->getGender()){
                    score = score + (float)mainArr->get(i)->getWeight();
                }
            }

            // if Age -> adding criteria as follows
            if(mainArr->get(i)->getName() == "Age"){

                // converts string to int
                stringstream value(mainArr->get(i)->getValue());
                float clientVal = 0.0;
                value >> clientVal;

                // calculation
                float ageYears = ((float)a->getAge()/12);
                float absVal = abs(ageYears - clientVal);
                float divVal = absVal/ 10.0;

                if(divVal > 1.0){

                    score = (float)score + 1.0;

                }
                else {
                    score = (float)score + (float)mainArr->get(i)->getWeight() * (1.0 - divVal);
                }
            }
    }
    return score;
}

// compute the score and add the match to teh deired match lists
void Shelter::computeMatches(MatchListByScore& mS, MatchListByClient& mC){

    float score = 0.0;

    for(int i =0; i<numClient; ++i){

        for(int j = 0; j < numAnimal; ++j){

            score = calculateScore(clientsArr[i], animalsArr[j]);

            if(score != 0.0){
                Match* newMatch = new Match(animalsArr[j], clientsArr[i], score);

                mS.add(newMatch);
                mC.add(newMatch);
            }
        }
    }

}
