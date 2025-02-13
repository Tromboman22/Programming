// Name: Samuel Pineau, Ethan Fadlon 
// ID: 4031432, 40314189

#include "Time.h"
#include <iostream>
using namespace std; 
 

Time::Time() {
    cout << "Constructor Time() is called" << endl;
    hour = 0;
    minute = 0;
    second = 0;	
}

void Time::setTime(int h, int m, int s) {
   hour = ( h >= 0 && h < 24 ) ? h : 0;                     
   minute = ( m >= 0 && m < 60 ) ? m : 0;                   
   second = ( s >= 0 && s < 60 ) ? s : 0;                   
}

void Time::printTime() const {
   if (hour < 10)
   {
      cout << "0";
   }
   cout << hour << ":";
   if (minute < 10)
   {
      cout << "0";
   }
   cout << minute << ":";
   if (second < 10)
   {
      cout << "0";
   }
   cout << second << endl;          
}

