// Name: Samuel Pineau 
// ID: 4031432

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
   cout << hour << ":" << minute << ":" << second << endl;          
}

