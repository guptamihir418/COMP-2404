// Mihir Gupta
// 101172281
#ifndef CRITERIA_H
#define CRITERIA_H

#include <string>
using namespace std;

class Criteria
{
  public:
    Criteria(string="", string="", int=0);

    string getName();
    string getValue();
    int    getWeight();
    void   print();

  private:
    string name;
    string value;
    int    weight;
};

#endif
