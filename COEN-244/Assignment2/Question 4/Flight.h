// Name: Samuel Pineau, Ethan Fadlon
// ID: 4031432

#pragma once
#include "Time.h"
#include "Date.h"
#include "Passenger.h"
#include <array>
using namespace std;
//#include "Passenger.h"


class Date;         //define date for use in functions

class Flight
{
    private:
        string id, departureCity, arrivalCity;
        Date* departureDate, *arrivalDate;
        int duration; //hours
		array <Passenger*, 100> seats;
        int seatCount = 0;

    public:
        Flight();
        Flight(string x, string dep, string arriv);
        Flight(const Flight &); //copy constructor
        string getID();
        string getDepCity();
        string getArrCity();
        Date getDepDate();
        Date getArrDate();
        int getDuration();
        void printinfo();
        bool checkDate(int x, int y, int z);

        //Functions unique to Q4.
        void addPassenger(const Passenger&);
        void removePassenger(string);
        bool searchPassenger(string);
        void displayPassenger();
        ~Flight();

};


/*
1. (15 points) Create a class called Flight that represents CoenAir flights. A flight has
a flight id (string), a departure city (string), an arrival city (string), a departure date (object
of class Date seen in the lectures), an arrival date (object of type Date), and a duration
in terms of hours (int).

The class should have:
- one or more constructors, 
- accessing functions,
- a copy constructor, 
- a destructor, 
- a function that prints information about a flight. 

Write a driver to test the class Flight. Note: You can reuse the class Date as it is.
Deliverables: A zip file that contains: 
STime.h, Time.cpp, Date.h, Date.cpp, Flight.h,
Flight.cpp, TestFlight.cpp
*/
