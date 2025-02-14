// Class composition: Class Date uses an object of class Time.

// Samuel Pineau, 4031432, file copied from Moodle --> "class composition Date Time"

#pragma once
#include <iostream>
using namespace std;

#include "Flight.h"
#include "Time.h"

class Time;

// class Date
class Date {
   public:
      Date();
      Date(int, int, int, int, int, int);   // sets day, month, year, hours, minutes, seconds
      void printDate() const;   	    // print date to the screen
      friend class Flight;

   private:
      int day, month, year;
      Time *time;   // a component object
};
