// Name: Samuel Pineau 
// ID: 4031432

#include "Flight.h"
#include "Date.h"
#include "Time.h"

#include<string>

Flight::Flight()
{
    id = "";
};
Flight::Flight(string x)
{
    id = x;
    //define the rest of the parameters
};
Flight::Flight(const Flight &)  //copy constructor
{

}; 
string Flight:: getID()
{
    return id;
};
string Flight:: getDepCity()
{
    return departureCity;
};
string Flight:: getArrCity()
{
    return arrivalCity;
};
Date Flight:: getDepDate()
{
    return departureDate;
};
Date Flight:: getArrDate()
{
    return arrivalDate;
};
int Flight:: getDuration()
{
    return duration;
};
void Flight:: printinfo()
{
    cout << "ID: " << id << endl;
    //print the rest of the data members
};
Flight::~Flight()   //Destructor
{

};
