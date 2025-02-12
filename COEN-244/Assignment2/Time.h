// Class composition: Class Date uses an object of class Time.

// Samuel Pineau, 4031432, file copied from Moodle --> "class composition Date Time"

#pragma once
#include <iostream>
using namespace std; 
 
//class Time
class Time {
  public:
    Time();
    void setTime( int, int ,int ); 
    void printTime() const;       

 private:
    int hour, minute, second;
};
