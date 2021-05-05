#ifndef DESCBEHAVIOUR_H
#define DESCBEHAVIOUR_H

#include "CompareBehaviour.h"

#include <iostream>
#include <string>

using namespace std;


template <class T>
class DescBehaviour : public CompareBehaviour<T>


/* Compares descending behaviour, find exact place to add*/
{

    public:

        virtual bool compare(T, T);

    private:


};

template <class T>
bool DescBehaviour<T>::compare(T t1, T t2){

    return (t1 > t2);

}



#endif