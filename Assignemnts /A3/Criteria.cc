// Mihir Gupta
// 101172281
#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

#include "Criteria.h"

Criteria::Criteria(string n, string v, int w)
  : name(n), value(v), weight(w) { }

string Criteria::getName()         { return name;   }
string Criteria::getValue()        { return value;  }
int    Criteria::getWeight()       { return weight; }

void Criteria::print()
{
  cout << setw(8)  << left  << name   << " " 
       << setw(20) << left  << value  << " " 
       << setw(2)  << right << weight << " " << endl;
}


