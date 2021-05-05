// Mihir Gupta
// 101172281

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#include "Recorder.h"

Recorder::Recorder(string n)
    :recorderName(n)
    { }

void Recorder::printRecords(){

    for(int i = 0; i<recordsColl.size(); ++i){

        if(recordsColl.size() == 0){
            cout<<"EMPTY LIST"<<endl;
        }
        
        cout<< recorderName<<":  GUEST    ";
        cout<< setw(25) << right << recordsColl[i]<<endl;
    }

    cout<<endl;
}

Recorder::~Recorder(){ }