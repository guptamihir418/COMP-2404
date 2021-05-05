// Mihir Gupta
// 101172281
#include <iostream>
using namespace std;

#include "CriteriaArray.h"


CriteriaArray::CriteriaArray() : size(0) {}

CriteriaArray::~CriteriaArray()
{
  for (int i=0; i<size; ++i)
    delete elements[i];
}

int CriteriaArray::getSize() { return size; }

Criteria* CriteriaArray::get(int index)
{
  if (index < 0 || index >= size)
    return NULL;

  return elements[index];
}

void CriteriaArray::add(Criteria* c)
{ 
  if (size >= MAX_SIZE) {
    cerr<<"Overflow"<<endl;
    exit(1);
  }

  elements[size++] = c;
}

void CriteriaArray::print() 
{ 
  for (int i=0; i<size; ++i) {
    cout << "-- ";
    elements[i]->print();
  }

  cout<<endl;
}

