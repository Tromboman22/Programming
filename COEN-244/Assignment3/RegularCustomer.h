// Samuel Pineau, 40317711

#pragma once
#include <iostream>
#include <string>
#include "Customer.h"

using namespace std;

class RegularCustomer: public Customer
{
    public:
        RegularCustomer();
        RegularCustomer(int, string, string);   //ID, First name, Last name
        RegularCustomer(const Customer&);
        void rentCar(Car*, int) override;
        void returnCar(int) override;
        bool isCorporate() override;
        void print() const override;
};