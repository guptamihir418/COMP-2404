#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H

#include <iostream>
#include <string>

using namespace std;



template <class T>

class CompareBehaviour{

/* Compares the behavior of two Types T*/

    public:

        virtual bool compare(T, T) = 0; 

    private:


};

#endif