// Mihir Gupta
// 101172281
#include <iostream>

using namespace std;


#include "Identifiable.h"

Identifiable::Identifiable(string s, int& i){


    stringstream ss;
    ss << s << "-" << i;
    id = ss.str();

    i++;

}

Identifiable::~Identifiable(){

}

// getter which gives ID
string Identifiable::getID(){
    return id;
}