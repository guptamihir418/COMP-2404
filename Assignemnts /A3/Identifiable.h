// Mihir Gupta
// 101172281
#ifndef  IDENTIFIABLE_H
#define IDENTIFIABLE_H

#include <sstream>
#include <string>

class Identifiable {

    public:
        Identifiable(string, int&);
        ~Identifiable();

        string getID();

    protected:
        string id;

};


#endif