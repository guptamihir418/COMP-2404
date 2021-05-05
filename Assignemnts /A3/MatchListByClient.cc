// Mihir Gupta
// 101172281
#include <iostream>
#include <string>

using namespace std;

#include "MatchListByClient.h"

MatchListByClient::MatchListByClient(){
}

void MatchListByClient::add(Match* m){

    Node* prevNode;
    Node* currNode;
    Node* newNode;

    newNode = new Node;
    newNode->data = m;
    newNode->next = NULL;

    currNode = head;
    prevNode = NULL;

    while(currNode != NULL){

        // to have client's score in descending order
        if(newNode->data->getClientID() == currNode->data->getClientID()){
            if(newNode->data->getScore() > currNode->data->getScore()){
                break;
            }
        }
        // to have client in ascending order
        if(newNode->data->getClientID() < currNode->data->getClientID()){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;

    }
    if(prevNode == NULL){
        head = newNode;
    }
    else{
        prevNode->next = newNode;
    }

    newNode->next = currNode;
}
