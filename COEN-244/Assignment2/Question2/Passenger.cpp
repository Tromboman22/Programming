// Name: Samuel Pineau
// ID: 4031432

#include "Passenger.h"
#include <iostream>
#include <string>

using namespace std;

Passenger::Passenger()          //Default constructor
{
 id = "";
};
Passenger::Passenger(string x)
{
    id = x;
};
Passenger::Passenger(const Passenger &)
{

};
string Passenger::getID()
{
    return id;
};
string Passenger::getFirstName()
{
    return firstName;
};
string Passenger::getLastName()
{
    return lastName;
};
string Passenger::geteAdress()
{
    return address;
};
string Passenger::getEmail()
{
    return email;
};
void Passenger::Print()
{

};
Passenger::~Passenger()         //Destructor
{

};