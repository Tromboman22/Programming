// Class composition: Class Date uses an object of class Time.

// File copied from Moodle --> "class composition Date Time"
// Name: Samuel Pineau, Ethan Fadlon
// ID: 4031432, 40314189

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
