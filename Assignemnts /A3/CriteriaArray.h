// Mihir Gupta
// 101172281
#ifndef DYNARRAY_H
#define DYNARRAY_H

#include "Criteria.h"
#include "defs.h"


class CriteriaArray
{
  public:
    CriteriaArray();
    ~CriteriaArray();
    void      add(Criteria*);
    int       getSize();
    Criteria* get(int);
    void      print();

  private:
    Criteria* elements[MAX_SIZE];
    int       size;
};

#endif

