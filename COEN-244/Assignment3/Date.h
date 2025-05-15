// Class composition: Class Date uses an object of class Time.

// Samuel Pineau, 4031432, file copied from Moodle --> "class composition Date Time"

#pragma once
#include <iostream>
using namespace std;
 
// class Date
class Date {
   public:
      Date();
      Date(int, int, int);   // sets day, month, year
      Date(const Date&);
      void printDate() const;   	    // print date to the screen
      bool isLeapYear(int);
      int daysInMonth(int, int);
      void addDays(int);      //Changes the date according to how many days the car is being rented

   private:
      int day, month, year;
};
