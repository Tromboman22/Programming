// Samuel Pineau, 40317711

#pragma once
#include <iostream>
#include <string>
#include <array>
#include "Customer.h"
#include "RegularCustomer.h"

using namespace std;

RegularCustomer::RegularCustomer(): Customer::Customer(){};

RegularCustomer::RegularCustomer(int num, string fnm, string lnm): Customer::Customer(num, fnm, lnm){print();};

RegularCustomer::RegularCustomer(const Customer& c): Customer::Customer(c){};

void RegularCustomer::rentCar(Car* num, int duration) 
{
    rentals[numCars++] = num;
    cout << "Renting a " << num->getType() << " over " << duration << " day(s) for the price of " << num->getPrice() * duration << "$\n";
};

void RegularCustomer::returnCar(int in) 
{
    //Proceed after veifying that 
    for(int i = 0; i < numCars; i++)
    {
        if(rentals[i]->getNum() == in)
        {
            numCars--;          //Increment car count and readjust array
            for(i; i < numCars; i++)
                rentals[i] = rentals[i+1];
            return;
        }
    }
};

bool RegularCustomer::isCorporate() {return false;};

void RegularCustomer::print() const 
{
    cout << name << " " << surname << ", ID: " << id << numCars << "rentals, regular customer" << endl;
};