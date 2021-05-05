// Mihir Gupta
// 101172281

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Calendar.h"
#define MAX_SIZE  64  // MAX elements for the array

//Ctor
Calendar::Calendar(string CalendarName){
    calName = CalendarName;
    currentDates = 0;
    datesArr = new Date*[MAX_SIZE];
}

//Dtor
Calendar::~Calendar(){

    cout<<"-- Calendar dtor"<<endl;

    for(int i = 0; i<currentDates; ++i){
        delete datesArr[i];
    }
    delete [] datesArr;
}


string Calendar::getCalendarName(){
    return calName;
}


bool Calendar:: add(Date* d){

    bool check;
    Date* temp1;
    Date* temp2;

    // Incorrect date check
    if(d->getValidate() == false){

        cout<<"Check your Date"<<endl;
        return false;
    }

    // Size error
    if(currentDates >= MAX_SIZE){
        cout<<"Can't Add More "<<endl;
        return false;
    }

    // Base Case: First element to add
    if(currentDates == 0){
        datesArr[0] = d;
        currentDates++;
        return true;
    }

    // shifting counter
    int count = currentDates + 1;

    // Finds the index to add
    for(int i = 0; i < currentDates; ++i){

        if(d->lessThan(datesArr[i]) == true){ 
            temp1 = datesArr[i];   
            datesArr[i] = d;       
            
            // shifting 
            for (int a = i; a < count; a++){

                temp2 = datesArr[a+1]; 
                datesArr[a+1] = temp1; 
                temp1 = temp2;      
            } 

            check = false;
            currentDates++;
            return true;
        }
        else{
            check = true;
        }
    }   
    if (check == true){

        datesArr[currentDates] = d;
        currentDates++;
        return true;
    }
    return false;
}


void Calendar::merge(Calendar* c){

    
    Date* temp;

    for(int i = 0; i < c->currentDates; i++){

        // copying data in temp
        temp = c->datesArr[i];

        // adding to "this" from temp
        // all error checking is done by add
        this->add(temp);

    }
}

// Print the dates in the Calendar
void Calendar::printDates(){

    for(int i = 0; i < currentDates; i++){
        cout<< i+1 << " Event is: ";
        cout<<endl;

        datesArr[i]->print();
        cout<<endl;
    }
}

// Prints the whole calendar
void Calendar::print(){
    cout<<endl;
    cout<<"Calendar Name: "<< calName<<endl<<endl;
    cout<<"Total Number of Event dates are: "<< currentDates <<endl;
    cout<<endl;    

// call to previous function
    printDates();

}
