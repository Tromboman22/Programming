// Name: Samuel Pineau
// ID: 4031432

#include <iostream>
using namespace std;
#include "Date.h"


Date::Date() {}; //default constructor
 
Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;

}

Date::Date(const Date& d)
{
    day = d.day;
    month = d.month;
    year = d.year;
};

void Date::printDate() const {
   cout << month << "/" << day << "/" << year << endl;

}

// Function to check if a year is a leap year
bool Date::isLeapYear(int yr) {
    return (yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0);
}

// Function to return the number of days in a given month
int Date::daysInMonth(int mth, int yr) {
    int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mth == 2 && isLeapYear(yr)) return 29; // February leap year case
    return daysPerMonth[mth - 1];
}

// Function to add days to the current date
void Date::addDays(int days) {
    day += days;

    // Adjust month and year if day exceeds current month's limit
    while (day > daysInMonth(month, year)) {
        day -= daysInMonth(month, year);
        month++;

        if (month > 12) { // If month exceeds December, reset to January and increment year
            month = 1;
            year++;
        }
    }
}