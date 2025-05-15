// Samuel Pineau, 40317711

#pragma once
#include <iostream>
#include <string>
#include <array>
#include "Customer.h"
#include "CorporateCustomer.h"

using namespace std;


CorporateCustomer::CorporateCustomer(): Customer::Customer(){};

CorporateCustomer::CorporateCustomer(int num, string fnm, string lnm): Customer::Customer(num, fnm, lnm){print();};

CorporateCustomer::CorporateCustomer(const Customer& c): Customer::Customer(c){};

void CorporateCustomer::rentCar(Car* num, int duration) 
{
    rentals[numCars++] = num;
    cout << "Renting a " << num->getType() << " over " << duration << " day(s), paid by the corporation\n";
};

void CorporateCustomer::returnCar(int in) 
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

bool CorporateCustomer::isCorporate() {return true;};

void CorporateCustomer::print() const 
{
    cout << name << " " << surname << ", ID: " << id << ", " << numCars << " rentals, corporate customer" << endl;
};