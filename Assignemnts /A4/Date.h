// Mihir Gupta
// 101172281

#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
  public:
    Date(int=0, int=0, int=2000);
    ~Date();
    Date(Date&);
    void setDate(int, int, int);
    bool lessThan (Date&);
    void print() const;
    bool equals(Date&);
    void add(int duration);

  

  private:
    int    day;
    int    month;
    int    year;
    int    lastDayInMonth();
    bool   leapYear();
    string getMonthStr() const;
};

#endif
