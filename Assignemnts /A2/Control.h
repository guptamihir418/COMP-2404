// Mihir Gupta
// 101172281

#ifndef CONTROL_H
#define CONTROL_H

#include "Telco.h"
#include "View.h"


class Control
{
  public:
  Control();
  ~Control();
  void launch();

  private:
  void initData(Telco*);
  void initSubscribers(Telco*);
  void initCalls(Telco*);

  Telco* tel;
  View v;

};

#endif
