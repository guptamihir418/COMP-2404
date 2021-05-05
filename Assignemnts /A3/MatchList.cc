// Mihir Gupta
// 101172281
#include <iostream>
#include <string>
using namespace std;

#include "MatchList.h"

MatchList::MatchList() : head(NULL) { }

// deletes the current node
MatchList::~MatchList()
{

    Node* currNode;
    Node* nextNode;

    currNode = head;

    while (currNode != NULL) {

        nextNode = currNode->next;
        delete currNode;


        currNode = nextNode;
    }

}



void MatchList::print()
{
    Node* currNode = head;

    while (currNode != NULL) {
        currNode->data->print();
        currNode = currNode->next;
    }
}

// cleans up the data
void MatchList::cleanup(){
    
    Node* currNode;
    Node* nextNode;

    currNode = head;

    while (currNode != NULL) {

        nextNode = currNode->next;
        delete currNode->data;

        currNode = nextNode;
    }

}
