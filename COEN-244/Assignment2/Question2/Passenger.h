// Name: Samuel Pineau
// ID: 4031432

#pragma once
#include <string>

using namespace std;

class Passenger
{
    private:
        string id, firstName, lastName, address, email;

    public:
        Passenger();                    //Default constructor
        Passenger(string ID, string FN, string LN, string AD, string EM);
        Passenger(const Passenger &);   //Copy constructor
        string getID();
        string getFirstName();
        string getLastName();
        string getAddress();
        string getEmail();
        void Print();
        ~Passenger();                   //Destructor
};




/*
Q2. (15 points) 
Write a class called Passenger that represents the passengers of CoenAir. 
A passenger has an id (string), first name (string), last name (string), address
(string), and email (string). 

The class should have 
- one or more constructors, 
- accessing functions, 
- a copy constructor, 
- a destructor, 
- a function that prints information about a passenger. 

Write a driver to test the Passenger class.
Deliverables: A zip file that contains three files: Passenger.h, Passenger.cpp,
TestPassenger.cpp
*/
