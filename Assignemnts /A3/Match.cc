// Mihir Gupta
// 101172281
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Match.h"

Match::Match(Animal* a, Client* c, float matchScore)
    :animalInvolved(a), clientInvolved(c), score(matchScore)
{ }

Match::~Match(){

}

float Match::getScore(){
    return score;
}

string Match::getClientID(){
    return clientInvolved->getID();
}

void Match::print(){


    cout <<setw(8)<<left<< clientInvolved->getID() 
    <<setw(12)<<right<< clientInvolved->getNAme();
    cout <<setw(12)<<right << animalInvolved->getID()
    <<setw(15)<<right<< animalInvolved->getName() ;
    cout  <<setw(15)<<right <<fixed<<setprecision(1)<< score 
    <<setw(4)<<left<< setfill(' ') << right << setw(3) << fixed << setprecision(0)<<"(" << score * 5 << "%)" << endl;


}

