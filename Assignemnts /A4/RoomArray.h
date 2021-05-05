// Mihir Gupta
// 101172281

#ifndef ROOMARRAY_H
#define ROOMARRAY_H

#include "defs.h"
#include "Room.h"


class RoomArray
{
  public:
    RoomArray();
    ~RoomArray();
    void  add(Room*);
    int   getSize();
    Room* get(int);
    void  print();

  private:
    Room* elements[MAX_ARR];
    int   size;
};

#endif

