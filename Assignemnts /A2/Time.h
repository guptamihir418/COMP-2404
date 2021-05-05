// Mihir Gupta
// 101172281

#ifndef TIME_H
#define TIME_H

class Time
{
  public:
    Time(int=0, int=0);
    bool greaterThan(Time*);
    void print();

  private:
    int  hours;
    int  minutes;
    void setTime(int, int);
    int  convertToMins();
};

#endif
