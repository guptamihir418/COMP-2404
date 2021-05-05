// Mihir Gupta
// 101172281

#ifndef CLIENT_H
#define CLIENT_H

#include <string>

#include "Identifiable.h"
#include "CriteriaArray.h"
#include "defs.h"

class Client : public Identifiable {

    public:
        Client(string="name");
        ~Client();
        string getNAme();
        CriteriaArray* getCriteriaArr();
        void addCriteria(Criteria*);
        void print();

    protected:



    private:
        static int nextID;
        string name;
        CriteriaArray CriteriaCollection;



};

#endif