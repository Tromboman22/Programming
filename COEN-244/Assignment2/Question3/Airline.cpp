// Name: Samuel Pineau
// ID: 4031432

#include "Airline.h"
#include "Passenger.h"
#include "Flight.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;


class Passenger;
class Flight;


Airline::Airline()
{
    name = "";
};
Airline::Airline(string name)
{

};
Airline::Airline(const Airline &)
{

};
string Airline::getName()
{

};
string Airline::getAddress()
{

};
Airline::~Airline()
{

};
void Airline::addFlight(const Flight&)
{

};
void Airline::removeFlight(string x)
{

};
bool Airline::searchFlight(string x)
{

};                    //Return true if flight exists
void Airline::displayFlights()
{

};
void Airline::displayFlightsFromTo(string x, string y)
{

};  //Print by departure and destination
