#ifndef ASCBEHAVIOUR_H
#define ASCBEHAVIOUR_H

#include <iostream>
#include <string>

using namespace std;

#include "CompareBehaviour.h"

template <class T>
class AscBehaviour : public CompareBehaviour<T>


/* This is RegionReportGenerator which is used in report 3 calculation
    and this is inherited class of ReportGenerator.cc*/

{

    public:

        virtual bool compare(T, T);

    private:


};

template <class T>
bool AscBehaviour<T>::compare(T t1, T t2){

    return (t2 > t1);

}


#endif