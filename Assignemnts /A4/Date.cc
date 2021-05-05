// Mihir Gupta
// 101172281

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"


Date::Date(int d, int m, int y)
{
  setDate(d, m, y);
}

Date::~Date()
{ }

Date::Date(Date& copyDate){

  day   = copyDate.day;
  month = copyDate.month;
  year  = copyDate.year;

}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}


int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
      (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr() const
{
  string monthStrings[] = { 
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}

bool Date::lessThan(Date& d){

  if(year < d.year){
    return true;
  }
  else if(year == d.year){
    if(month < d.month){
      return true;
    }

    else if(month == d.month){
      if(day < d.day){
        return true;
      }
    }
  }
  return false;

}

bool Date::equals(Date& d){
  if ((year == d.year) && (month == d.month) && (day == d.day)) {
    return true;
  }
  return false;
}

void Date::print() const{

    cout << year << "-" << month << "-" << day;

}



void Date::add(int duration){

  if(duration > 31){
    cout<<("INVALID DURATON\n");
    return;
  }

  int left;

  left = this->lastDayInMonth() - this->day;  // how many days we left in a month

  int finalLeft = duration - left;        // will that month be able to fit the duration


        // it will fit if finalLeft is +ve
        // it will not fit if the finalLeft is -ve


  if(finalLeft <= 0){
    this->day += duration;
  }

  else if(finalLeft > 0){

    if(this->month !=12){         

      this->day = finalLeft;        // newdate = what is left
      this->month += 1;             // new month = 1 + prev
    }
    else if(this->month == 12){

      this->day    = finalLeft;      // newdate = what is left
      this->month  = 1;              // december -> january
      this->year  += 1;              // year increased by 1
    }
  }


}