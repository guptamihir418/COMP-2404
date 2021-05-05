// Mihir Gupta
// 101172281
#ifndef ARRAY_H
#define ARRAY_H

#define MAX_ARR 64

#include "Call.h"

class Array
{
  public:
    Array();
    ~Array();
    Array(Array&); //ctor
    bool add(Call*);
    bool add(Array&);
    void print();
    void cleanup();
    int getSize();
    Call* get(int);

  private:
    Call* elements[MAX_ARR];
    int   size;
};

#endif

// cleanup to be done