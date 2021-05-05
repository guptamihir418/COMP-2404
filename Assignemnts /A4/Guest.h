// Mihir Gupta
// 101172281

#ifndef GUEST_H
#define GUEST_H

#include <string>

class Guest{

    public:
        Guest(string="Name", bool = false);
        string getName();
        bool getPremium();
        void print() const;
        void addPts(int);

    private:
        string name;
        bool isPremium;
        int loyaltyPoints;

};

#endif