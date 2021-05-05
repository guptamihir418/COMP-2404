// Mihir Gupta
// 101172281

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y)
{
  cout<<"in default ctor"<<endl;
  setDate(d, m, y);
}

Date::~Date()
{
  // cout<<"in dtor"<<endl;
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
    "January", "Februrary", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}

// checks the date if greter or not
bool Date::greaterThan(Date* d) {

  if(year > d->year){
    return true;
  }
  else if(year == d->year){
    if(month > d->month){
      return true;
    }
    else if(month == d->month){
      if(day > d->day){
        return true;
      }
    }
  }
  return false;
}

// check the date if equal or not
bool Date::equals(Date* d){
  
  if ( (year == d->year) && (month == d->month) && (day == d->day)){
    return true;
  }
  return false;
}

// print date
void Date::print(){

  cout << year << "-" << month << "-" << day << endl;
}

