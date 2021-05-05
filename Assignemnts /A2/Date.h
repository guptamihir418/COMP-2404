// Mihir Gupta
// 101172281

#ifndef DATE_H
#define DATE_H

class Date
{
  public:
    Date(int=0, int=0, int=2000);
    ~Date();
    void setDate(int, int, int);
    void printShort();
    void printLong();
    void printLong() const;

    bool greaterThan(Date*);
    bool equals(Date*);
    void print();

  private:
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr() const;
};

#endif
