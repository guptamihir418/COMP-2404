// Mihir Gupta
// 101172281

#include <iostream>
#include <string>

using namespace std;

#include "Telco.h"

#define MAX_ARR 64

Telco::Telco(string n, int numOfSubs)
    :   name(n)

{
    numSubs = 0;
    // cout<<"INside Telco ctor...."<<endl;
}


Telco::~Telco(){  

    // cout<<"inside telco dtor"<<endl;
    for(int i = 0; i < numSubs; ++i){
        delete subsArr[i];
    }

    CallsArr.cleanup();

}


// add subscriber to the end of the subs array
void Telco::addSub(Subscriber* s){

    // basic error checking
    if(numSubs >= MAX_ARR){
        return;
    }

    subsArr[numSubs] = s;
    ++numSubs;

}
// Helper function
// returns the index of the source Num if found, else return -1
int Telco::sourceIndex(string srcNum){

    for(int i = 0; i < numSubs; ++i){

        if(subsArr[i]->getPhoneNum() == srcNum){
            return i;

        }
    }
    return -1;
}

// Helper function
// returns the index of the Destination Num if found, else return -1
int Telco::destIndex(string destNum){

    for(int i = 0; i < numSubs; ++i){

        if(subsArr[i]->getPhoneNum() == destNum){
            return i;

        }
    }
    return -1;
}



void Telco::addCall(string srcNum, string destNum, 
                        int y, int m, int d,
                        int h, int min, int dur){

    Call* c = new Call(srcNum, destNum, dur, d, m, y, h, min); // dynamically allocating c

    // saving the values in variables so that function calling time can be saved and run time can be saved
    int srcIndex = sourceIndex(srcNum);
    int desIndex = destIndex(destNum);

    // if both source and destination is found we add to desired arrays
    if((srcIndex != -1) && (desIndex != -1)){

        subsArr[srcIndex]->addOutgoing(c);
        subsArr[desIndex]->addIncoming(c);
        CallsArr.add(c);

    }

    // if both source  is found we add to desired array
    else if(srcIndex != -1){

        subsArr[srcIndex]->addOutgoing(c);
        CallsArr.add(c);

    }
    // if both destination is found we add to desired array
    else if(desIndex != -1){
        subsArr[desIndex]->addIncoming(c);
        CallsArr.add(c);

    }

    delete c;

}


// prints the telco
void Telco::print(){
    for(int i = 0; i<numSubs; i++){
        subsArr[i]->print();
        cout<<endl;
    }
}

// Helper function which checks if the number exists in the array and returns teh index
int Telco::NumExists(string num, string arr[], int arrSize){

    if(arrSize > MAX_ARR){
        cout<<"SIZE TOO BIG"<<endl;
        return -1;
    }

    for(int i = 0; i < arrSize; ++i){
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}



void Telco::computeFreqCaller(string destNum){
    
    // we check if destNum is any subscribers number
    // if not we dont proceed -> print something silly

    // if found -> we go to that subscribers incoming calls

    // now we make two arrays -> 1 keep all incoming calls
                            // 2 to keep counts of those incoming calls

    // if arr1 is empty we add first incoming call to it and set arr2's same index to count 1

    // now if not empty we add it to last index and count to same index of arr1 to arr2

    // if number repeats -> we go to the index of that number and increases the count by 1

    // do this till the incomingcalls array is end

    string NumArr[MAX_ARR];  // nums array stores phone numbers of the sub's incoming calls
    int countArr[MAX_ARR];    // stores the number of times that caller called in the exact same index

    int sizeBothArr = 0;  // size of both the array which is same

    int indexArr[MAX_ARR];
    int indexArrSize=0;

    // iterate through subs array
    for(int i = 0; i < numSubs; ++i){

        if(subsArr[i]->getPhoneNum() == destNum){ // get the subscriber 

            int InSize = subsArr[i]->getInCallArr()->getSize(); // save the size of incoming calls array

            // iterate through sub's incoming calls array
            for(int j = 0; j < InSize; ++j){

                // error checking
                if(sizeBothArr >= MAX_ARR){ 
                    cout<<"INVALID SIZE"<<endl;
                    return;
                }

                // if Numsarr and countArr is empty we add it
                if(sizeBothArr == 0){

                    NumArr[0] = subsArr[i]->getInCallArr()->get(0)->getSrcNum();
                    countArr[0] = 1;
                    sizeBothArr++;
                }

                else{
                    
                    // we store the phone number 
                    string phn = subsArr[i]->getInCallArr()->get(j)->getSrcNum();

                    // this will give me the index of the "phone" if it exists in NumArr
                    int index = NumExists(phn, NumArr, sizeBothArr);

                    // if it exists
                    if(index != -1){

                        // we increase the count of that number in the in countArr by 1
                        int tempVal;
                        tempVal = countArr[index];
                        countArr[index] = tempVal+1;
                    }
                    else{  // means num is new

                        // we add it at the end
                        NumArr[sizeBothArr] = phn;
                        countArr[sizeBothArr]= 1;
                        sizeBothArr++;
                    }
                }
                
            }
            // now we have out 2 arrays ready
            // we need to print frequent caller's phone number and all the calls made should be printed

            // to do this we need to find the highest value in countArr
            // we need to go to the highest value's -> index in the countArr and use the index to get the number of 
            // that frequent caller, now we iterate over incoming calls and print every call made by that number

            // we compare highest to each element in the count arr and for the value of index we get we use the same index to print
            

            // going through count array to get highest
            int highest=0;
            for(int b = 0; b<sizeBothArr; ++b){

                if(highest < countArr[b]){
                    highest = countArr[b];
                }
            }

            // this loop adds the indices of highest occurrence in the indexArr
            for(int c = 0; c<sizeBothArr; ++c){
                if(highest == countArr[c]){
                    
                    // cout<<NumArr

                    indexArr[indexArrSize] = c;
                    indexArrSize++;
                    // cout<<indexArr[indexArrSize-1]<<endl;
                    //cout<<NumArr[]<<endl;
                }
            }

            // this prints everything
            for(int d = 0; d < indexArrSize; ++d){

                cout<<endl;
                cout<<"PRINTING FREQUENT CALLERS "<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"Phone Number is: ";
                cout<<NumArr[indexArr[d]];
                cout<<endl;
                for(int e = 0; e < InSize; ++e){
                    string check = subsArr[i]->getInCallArr()->get(e)->getSrcNum();
                    if(NumArr[indexArr[d]] == check){
                        Call* toPrint = subsArr[i]->getInCallArr()->get(e);
                        toPrint->print();
                        cout<<endl;
                        cout<<endl;

                    }

                }
                cout<<endl;
            }


        }

    }
    // error checking
    if(sizeBothArr == 0){
        cout<<"NO CALLS FOUND (Frequent caller)"<<endl;
    }

}

// same function as above
void Telco::computeFreqCalled(string srcNum){

    string NumArr[MAX_ARR];
    int countArr[MAX_ARR];

    int sizeBothArr = 0;

    int indexArr[MAX_ARR];
    int indexArrSize = 0;

    // iterate through subs array
    for(int i = 0; i < numSubs; ++i){

        if(subsArr[i]->getPhoneNum() == srcNum){

            int OutSize = subsArr[i]->getOutCallArr()->getSize();

            for(int j = 0; j < OutSize; ++j){

                if(sizeBothArr >= MAX_ARR){
                    cout<<"INVALID SIZE"<<endl;
                    return;
                }

                if(sizeBothArr == 0){
                    NumArr[0] = subsArr[i]->getOutCallArr()->get(0)->getDestNum();
                    countArr[0] = 1;
                    sizeBothArr++;
                }

                else{
                    string phn = subsArr[i]->getOutCallArr()->get(j)->getDestNum();

                    int index = NumExists(phn, NumArr, sizeBothArr);

                    if(index != -1){

                        int tempVal;
                        tempVal = countArr[index];
                        countArr[index] = tempVal+1;
                    }

                    else{
                        NumArr[sizeBothArr] = phn;
                        countArr[sizeBothArr] = 1;
                        sizeBothArr++;
                    }
                }

            }

            int highest = 0;
            for(int b = 0; b<sizeBothArr; ++b){

                if(highest < countArr[b]){
                    highest = countArr[b];
                }
            }

            for(int c = 0; c<sizeBothArr; ++c){
                if(highest == countArr[c]){
                    indexArr[indexArrSize] = c;
                    indexArrSize++;
                }
            }

            for(int d = 0; d < indexArrSize; ++d){
                cout<<endl;
                cout<<"Printing Frequently Called List "<<endl;
                cout<<NumArr[indexArr[d]];
                cout<<endl;

                for(int e = 0; e < OutSize; ++e){
                    string check = subsArr[i]->getOutCallArr()->get(e)->getDestNum();
                    if(NumArr[indexArr[d]] == check){
                        Call* toPrint = subsArr[i]->getOutCallArr()->get(e);
                        toPrint->print();
                        cout<<endl;
                        cout<<endl;

                    }
                }

                cout<<endl;

            }
        }
    }

    if(sizeBothArr == 0){
        cout<<"NO CALLS FOUND (Frequently Called)"<<endl;
    }

}
