// Mihir Gupta
// 101172281

#include <iostream>
using namespace std;
#include <string>

#include "Control.h"


Control::Control(){

    resMgr  = new ResManager();
    hotel   = new Hotel("Grand Walk", resMgr);
    resMgr->setHotel(hotel);

  StayRecorder*    SR = new StayRecorder("Stay Recorder");
  GuestRecorder*   GR = new GuestRecorder("Guest Recorder");
  UpgradeRecorder* UR = new UpgradeRecorder("Upgrade Recorder");

  resMgr->subscribe(SR);
  resMgr->subscribe(GR);
  resMgr->subscribe(UR);

}

Control::~Control(){
  delete resMgr;
  delete hotel;
}



void Control::initHotel()
{

  hotel->addGuest(new Guest("Juliet", true));
  hotel->addGuest(new Guest("Ben", true));
  hotel->addGuest(new Guest("Goodwin"));
  hotel->addGuest(new Guest("Harper", true));
  hotel->addGuest(new Guest("Ethan"));
  hotel->addGuest(new Guest("Horace"));
  hotel->addGuest(new Guest("Aimee"));

  hotel->addRoom(new Room(C_SUITE, 501, 1500));
  hotel->addRoom(new Room(C_PREM, 410, 700));
  hotel->addRoom(new Room(C_PREM, 420, 700));
  hotel->addRoom(new Room(C_REG, 322, 300));
  hotel->addRoom(new Room(C_REG, 324, 300));
  hotel->addRoom(new Room(C_REG, 326, 300));
  hotel->addRoom(new Room(C_REG, 212, 200));
  hotel->addRoom(new Room(C_REG, 214, 200));
  hotel->addRoom(new Room(C_REG, 216, 200));
  hotel->addRoom(new Room(C_REG, 218, 200));

  resMgr->addReservation("Ben",     2021, 5, 11,  4, C_PREM);
  resMgr->addReservation("Juliet",  2021, 5, 10,  3, C_PREM);
  resMgr->addReservation("Horace",  2021, 5, 28, 10, C_PREM);
  resMgr->addReservation("Aimee",   2021, 5, 28,  8, C_PREM);
  resMgr->addReservation("Sophie",  2021, 5, 28,  8, C_PREM);
  resMgr->addReservation("Harper",  2021, 5, 12,  1, C_PREM);
  resMgr->addReservation("Harper",  2021, 5, 12,  1, C_REG);
  resMgr->addReservation("Ethan",   2021, 5,  8,  7, C_REG);
  resMgr->addReservation("Ethan",   2021, 5, 28, 10, C_REG);
  resMgr->addReservation("Timmy",   2021, 5, 28,  8, C_REG);
  resMgr->addReservation("Horace",  2021, 5, 25,  2, C_REG);
  resMgr->addReservation("Goodwin", 2021, 5, 25, 12, C_REG);
  resMgr->addReservation("Ben",     2021, 5, 27,  5, C_REG);
  resMgr->addReservation("Harper",  2021, 5, 29,  2, C_SUITE);
  resMgr->addReservation("Juliet",  2021, 5, 30,  1, C_SUITE);

}

void Control::launch(){

  initHotel();

  int choice;

  // keep showing menu until user exits
  while(1){

    v.showMenu(choice);

    if(choice == 1){
      resMgr->print();
    }

    else if(choice == 2){
      hotel->printRooms();
    }

    else if(choice == 3){
      hotel->printGuests();
    }

    else if(choice == 4){
      resMgr->printRecords();
    }

    else if(choice == 0){
      break;  // breaks out of the loop
    }
  }
}

