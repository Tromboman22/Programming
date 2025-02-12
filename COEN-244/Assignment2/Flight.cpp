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

};
string Flight:: getDepCity()
{

};
string Flight:: getArrCity()
{

};
Date Flight:: getDepDate()
{

};
Date Flight:: getArrDate()
{

};
int Flight:: getDuration()
{

};
void Flight:: printinfo()
{

};
Flight::~Flight()   //Destructor
{

};