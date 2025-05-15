// Samuel Pineau, 40317711

#include "Customer.h"
#include <iostream>
#include <string>

using namespace std;


Customer::Customer(){};

Customer::Customer(int num, string nm, string snm) : id(num), name(nm), surname(snm){};

Customer::Customer(const Customer& c): id(c.id), name(c.name), surname(c.surname){};

int Customer::getid(){return id;};

string Customer::getname(){return name;};

string Customer::getsurname(){return surname;};

int Customer::getNumRents(){return numCars;};

void Customer::setname(string nm){name = nm;};

void Customer::setsurname(string snm){surname = snm;};

void Customer::rentCar(Car* num, int duration)
{
    rentals[numCars++] = num; 
};

bool Customer::hasCar(int in)
{
    //check if a customer has a given car by ID
    for(int i = 0; i < numCars; i++)
    {
        if(in == rentals[i]->getNum())
            return true;               
    }
    return false;
};

void Customer::returnCar(int num)
{
    bool check = false;
    for(int i = 0; i < numCars; i++)
    {
        if(rentals[i]->getNum() == num)   //Verification if this is the right customer will be done in company function
        {
            check = true;
            numCars--;
        }
        if(check && numCars-i+1)  //Check needs to be true && i is not the last index in array, 
        {
            rentals[i] = rentals[i+1];
        }
    }
};

bool Customer::isCorporate(){return false;};

void Customer::print() const
{
    cout << "Name: " << surname << " " << name << endl
    << "ID: " << id << endl
    << "Cars in rental (by ID#): ";
    bool comma = false;
    //list cars by ID#
    for(int i = 0; i < numCars; i ++)
    {
        if(comma)
            cout << ", ";
        else
            comma = true;

        cout << rentals[i];
    }
};

Customer::~Customer() = default;    //Default destructor, cars to be de-allocated stored in company object