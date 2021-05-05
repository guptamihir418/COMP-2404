// Mihir Gupta
// 101172281

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Guest.h"

Guest::Guest(string n, bool prem)
    : name(n), isPremium(prem)

    {
        loyaltyPoints = 0;
    }

void Guest::addPts(int x){
    loyaltyPoints += x;
}


string Guest::getName(){
    return name;
}

bool Guest::getPremium(){
    return isPremium;
}

void Guest::print() const {

    string prem;
    
    prem = (isPremium == 1) ? prem = "Premium Guest": "Regular Guest";

    cout<<"-- "     <<setw(10) << left << name
                    <<setw(20) << left << prem
                    <<setw(1) << left << loyaltyPoints<<" Pts";
}