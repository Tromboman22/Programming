// Name: Samuel Pineau
// ID: 4031432

#pragma once
#include "Passenger.h"
#include "Flight.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

class Passenger;
class Flight;

class Airline
{
    private:
        string name;
        string address;
        array <Flight*, 100> flights;

    public:
        Airline();
        Airline(string name);
        Airline(const Airline &);
        string getName();
        string getAddress();
        ~Airline();
        void addFlight(const Flight&);
        void removeFlight(string x);
        bool searchFlight(string x);                    //Return true if flight exists
        void displayFlights();
        void displayFlightsFromTo(string x, string y);  //Print by departure and destination
};



/*
Q3. (25 points) We want to create a class called Airline that keeps track of the flights of
CoenAir. 

The class Airline has the following attributes: 
the name of the company (string),
the address of the headquarter of the company (string), 
an array of objects of class Flight

Note that vectors can be used instead of arrays. The question as to which data structure
to use and why will be the subject of one of the lectures. 

The class should have:
- one or more constructors, 
- accessing functions, 
- a copy constructor, 
- a destructor, 

It should also include the following functions:
• addFlight(const Flight&): This function adds a flight object to the array of flights.
• removeFlight(string): This function removes a flight from the array of flights. It takes the flight id as input.
• searchFlight(string): This function returns true if a given flight exists. It takes the flight id as input.
• displayFlights(): This function display all the flights of the airline.
• displayFlightsFromTo(string, string): This function takes the departure and arrival cities and displays 
  information about flights that take off and land at these cities.


Deliverables: A zip file with all the header and cpp files.
*/