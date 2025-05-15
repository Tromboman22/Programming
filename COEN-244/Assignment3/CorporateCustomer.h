// Samuel Pineau, 40317711

#pragma once
#include <iostream>
#include <string>
#include <array>
#include "Customer.h"

using namespace std;

class CorporateCustomer: public Customer
{
    public:
        CorporateCustomer();
        CorporateCustomer(int, string, string); //ID, First name, Last name
        CorporateCustomer(const Customer&);
        void rentCar(Car*, int) override;
        void returnCar(int) override;
        bool isCorporate() override;
        void print() const override;
};