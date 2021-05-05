// Mihir Gupta
// 101172281
#include <iostream>
#include <string>

using namespace std;
#define MAX_SIZE 128

#include "Client.h"

int Client::nextID = 7001;

Client::Client(string n)
    : Identifiable("C", nextID), name(n)
{
}

Client::~Client(){
}

CriteriaArray* Client::getCriteriaArr(){
    return &CriteriaCollection;
}

void Client::addCriteria(Criteria* c){

    if(CriteriaCollection.getSize() >= MAX_SIZE){
        cerr<<"Overflow"<<endl;
        exit(1);
    }

    CriteriaCollection.add(c);

}

string Client::getNAme(){
    return name;
}

void Client::print(){

    //cout<<"Printing Client's Data "<<endl<<endl;
    cout<< id   << "    ";
    cout<< name << "    " <<endl;
    CriteriaCollection.print();
    cout<<endl;
}