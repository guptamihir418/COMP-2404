// Mihir Gupta
// 101172281

#include <iostream>
using namespace std;

#include "RoomArray.h"


RoomArray::RoomArray()
{
  size = 0;
}

RoomArray::~RoomArray()
{
  for (int i=0; i<size; ++i)
    delete elements[i];
}

int RoomArray::getSize() { return size; }

Room* RoomArray::get(int index)
{
  if (index < 0 || index >= size)
    return NULL;

  return elements[index];
}

void RoomArray::add(Room* r)
{ 
  if (size >= MAX_ARR)
    return;

  elements[size++] = r;
}

void RoomArray::print()
{ 
  for (int i=0; i<size; ++i)
    elements[i]->print();

  cout<<endl;
}

