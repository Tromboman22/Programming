// Class composition: Class Date uses an object of class Time.

// Samuel Pineau, 4031432, file copied from Moodle --> "class composition Date Time"

#pragma once
#include <iostream>
#include "Date.h"
using namespace std; 
 
//class Time
class Time {
  public:
    Time();
    void setTime( int, int ,int ); 
    void printTime() const;       
    friend class Date;

 private:
    int hour, minute, second;
};
