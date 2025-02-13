// Name: Samuel Pineau
// ID: 4031432

#include "Passenger.h"
#include <iostream>
#include <string>

using namespace std;

Passenger::Passenger()          //Default constructor
{
    id = "", firstName = " ", lastName = " ", address = " ", email = " ";
};
Passenger::Passenger(string ID, string FN, string LN, string AD, string EM)
{
    id = ID;
    firstName = FN;
    lastName = LN;
    address = AD;
    email = EM;
};
Passenger::Passenger(const Passenger &p)
{
    id = p.id;
    firstName = p.firstName;
    lastName = p.lastName;
    address = p.address;
    email = p.email;
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
string Passenger::getAddress()
{
    return address;
};
string Passenger::getEmail()
{
    return email;
};
void Passenger::Print()
{
    cout << "Passenger Info: \n"
        << "ID: " << id << endl
        << "Name: " << firstName << " " << lastName
        << "\nAddress: " << address
        << "\nEmail: " << email << endl;
};
Passenger::~Passenger()         //Destructor
{
    //nothing to delete
};
