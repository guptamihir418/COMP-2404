// Mihir Gupta
// 101172281

#include <iostream>
using namespace std;

#include "Array.h"

Array::Array(){

  size = 0;
}

Array::~Array(){

  

    // cout<<"dtor array....."<<endl;
}

bool Array::add(Call* c){
  
  // error checking
  if (size >= MAX_ARR)
    return false;

  // base case
  if (size == 0){
    elements[0] = c;
    ++size;
    return true;
  }

  if (size > 0){

    Call* temp;
    int index;

    // this for loop will give the index we want to add in
    for(int i = 0; i < size; ++i){

        index = i; // storing the index's value in variable

      // comparing to get to the desired index
      if(c->greaterThan(elements[i]) == true){

        // this for loop does shifting from last to index
        for(int j = size-1; j >= index; --j){

          // stores jth value and shift it one further
          temp = elements[j];
          elements[j+1] = temp;
        }

        // we made space for the element at index
        // we add element and increase size
        elements[index] = c;
        ++size;
        return true;
      }

        // check for last element 
      else if(c->greaterThan(elements[i]) == false){

        if(index == size-1){

          // we add it at the last
          elements[size] = c;
          ++size;
          return true;
        }
      }
    }
  }
  return false;
}

// adds the elements of arr to "this"
bool Array::add(Array& arr){

  // basic error checking
  if(this->size >= MAX_ARR){
    cout<<"NO MORE ITEMS CAN BE ADDED";
    return false;
  }

  for(int i = 0; i < arr.size; ++i){

    this->add(arr.elements[i]);
  }

  return true;
}

// prints the elements of array
void Array::print(){

  cout << endl << endl << "CALLS:" << endl;
  for (int i=0; i<size; ++i){
    elements[i]->print();
    cout << endl;
  }
}

// copy constructor -> copies the whole array to the other
Array::Array(Array& copyCallArr){

  size = copyCallArr.getSize();
  Call* temp;

  for(int i = 0; i < copyCallArr.size; ++i){
    temp = copyCallArr.elements[i];
    elements[i] = temp;
  }
}


// to be done
void Array::cleanup(){

  for(int i = 0; i <= size; ++i){
    delete elements[i];
  }

}


// getter function to get size of array
int Array::getSize(){
  return size;
}

// getter function to get element at index i in the array
Call* Array::get(int i){

  // error checking
  if (i >= size){
    cout<<"Wrong index given"<<endl;
    return 0;
  }

  return elements[i];
}




