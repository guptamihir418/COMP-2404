// Mihir Gupta
// 101172281

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

//ctor
Date::Date(string eventName, int d, int m, int y, int startHour, int startMin, int dur, bool reccur, int reccurWeeks){

  isReccuring = reccur;
  event = eventName;
  
  // validating date
  validDate = validate(d, m, y, startHour, startMin, dur);

  
  setDate(d, m, y);

  // converting to minutes from midnight
  startTime = startHour * 60 + startMin;
  duration = dur;

  if (isReccuring == true){
    weeksRecurring = reccur; 
  }
  weeksRecurring = 0;

}


bool Date::getValidate(){
  return validDate;
}

// copy-ctor
Date::Date(Date& copyDate){

  day = copyDate.day;
  month = copyDate.month;
  year = copyDate.year;
  event = copyDate.event;
  startTime = copyDate.startTime;
  duration = copyDate.duration;
  isReccuring = copyDate.isReccuring;
  weeksRecurring = copyDate.weeksRecurring;
  validDate = copyDate.validDate;

  cout<<"COPY-CTOR IS WORKING"<<endl;

}

// given function
void Date::setDate(int d,int m,int y){

  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12 ) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

// Validating the date/time
bool Date::validate(int d, int m, int y, int startHour, int startMin, int dur){

  // error  checking
  if (y < 0) return false;
  if (m < 0 || m > 12) return false;
  if (d < 0 || d > lastDayInMonth()) return false;
  if (startHour < 0 || startHour > 24) return false;
  if (startMin < 0 || startMin > 60) return false;
  if (dur < 0) return false;
  else return true;

}

// compares two dates
bool Date::lessThan(Date* d){

  if(year < d->year){
    return true;
  }
  else if(year == d->year){
    if(month < d->month){
      return true;
    }
    else if(month == d->month){
      if(day < d->day){
        return true;
      }
      else if(day == d->day){
        if(startTime < d->startTime){
          return true;
        }
      }
    }
  }
  return false;
}


void Date::print(){

  int startT = startTime;
  int endT = startT + duration;

  int startHour = startT/60;
  int startMin = startT - (startHour*60);

  int endHour = endT/60;
  int endMin = endT - (endHour*60);


  cout<<endl<<"Event name: "<<event<<endl; //print event name
  cout<<"Date: "<<getMonthStr()<<" "<<day<<", "<<year<<endl; // prints date
  cout<<"Start time: "<<startHour<<":"<<startMin<<endl;
  cout<<"End time: "<<endHour<<":"<<endMin<<endl;


}


// given function
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

// Given Method
bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

// Given Method
string Date::getMonthStr()
{
  string monthStrings[] = { 
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}

