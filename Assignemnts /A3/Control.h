// Mihir Gupta
// 101172281
#ifndef CONTROL_H
#define CONTROL_H

#include "Client.h"
#include "Animal.h"
#include "Shelter.h"
#include "View.h"
#include "MatchListByClient.h"
#include "MatchListByScore.h"
#include "MatchList.h"


class Control
{
  public:
    Control();
    ~Control();
    void launch();
    


  private:
    void initShelter();
    void initClients();
    void initAnimals();

    Shelter* shelter;
    View v;


};

#endif
