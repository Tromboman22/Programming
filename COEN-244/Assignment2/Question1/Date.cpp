// Name: Samuel Pineau 
// ID: 4031432


#include <iostream>
using namespace std;
#include "Date.h"
#include "Time.h"

Date::Date() {}; //default constructor

Date::Date(int d, int m, int y, int hour, int min, int sec) {
    cout << "Constructor Date(...) is called" << endl;
    day = d;
    month = m;
    year = y;
    time = new Time();
    time->setTime(hour, min, sec);
}

void Date::printDate() const {
   cout << month << "/" << day << "/" << year << " at ";
   time->printTime() ;
}

