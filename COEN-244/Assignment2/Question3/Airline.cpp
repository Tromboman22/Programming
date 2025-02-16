// Name: Samuel Pineau, Ethan Fadlon
// ID: 4031432, 40314189

#include "Airline.h"
#include "Passenger.h"
#include "Flight.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;



Airline::Airline()                          //Default constructor
{
    name = "";
    address = "";
};
Airline::Airline(string nm, string adr)     //Constructor
{
    name = nm;
    address = adr;
};
Airline::Airline(const Airline & air)       //copy constructor
{
    name = air.name;
    address = air.address;
};
string Airline::getName()
{
    return name;
};
string Airline::getAddress()
{
    return address;
};
Airline::~Airline()                         //Destructor
{
    for(int i = 0; i < flightnum; i++)
    {
        flights[i]->~Flight();
        delete flights[i];
    }
};
void Airline::addFlight(const Flight& cpy)
{
    if(flightnum < 100)
    {
        Flight *dup = new Flight(cpy);
        flights[flightnum] = dup;
        flightnum++;
    }
};
void Airline::removeFlight(string x)
{
    bool trigger = false;
    for(int i = 0; i < flightnum; i++)      //remove a flight, decrease the number of flights and increment the flights array
    {
        if(flights[i]->getID() == x)
        {
            delete flights[i];
            flightnum -= 1;
            trigger = true;
        }
        if(trigger)                         //enabled if trigger became true
        {
            flights[i] = flights[i+1];
            delete flights[i+1];
        }
    }
    //Confirmation message
    if(trigger == false)
    {
        cout << "Invalid flight id" << endl;
    }
    else
    {
        cout << "Successfully deleted flight" << endl;
    }
};
bool Airline::searchFlight(string x)        //Return true if flight exists
{
    bool trigger = false;                   //keep track if flight gets found
    for(int i = 0; i < flightnum; i++)
    {
        if(flights[i]->getID() == x)
        {
            trigger = true;
            break;
        }
    }
    return trigger;
};                    
void Airline::displayFlights()              //prints all the flights
{
    for(int i = 0; i < flightnum; i++)
    {
        flights[i]->printinfo();
        cout << endl; 
    }
};
void Airline::displayFlightsFromTo(string depct, string arrct) 
{
    //depct is departure city
    //arrct is arrival city
    bool trigger = false;
    for(int i = 0; i < flightnum; i++)
    {
        if(flights[i]->getDepCity() == depct && flights[i]->getArrCity() == arrct)
        {
            trigger = true;
            flights[i]->printinfo();
            cout << endl;
        }
    }
    if(!trigger)
    {
        cout << "No flights were found with a corresponding departure city and destination" << endl;
    }
};  //Print by departure and destination
bool Airline::flightCount() //Check if there are flights registered in the airline
{
    if(flightnum == 0)
        return false;
    return true;
}
