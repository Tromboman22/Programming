// Samuel Pineau, 40317711
// Customer class

#pragma once
#include <iostream>
#include <string>
#include <array>
#include "Car.h"

using namespace std;

class Customer
{
    protected:
        int id;                     //Customer ID #
        string name, surname;       //Customer name
        int numCars;                //Amount of cars rented
        array<Car*, 10> rentals;     //Car ID numbers for rentals
    
    public:
        Customer();
        Customer(int, string, string);
        Customer(const Customer&);
        int getid();
        string getname();
        string getsurname();
        int getNumRents();
        void setname(string);
        void setsurname(string);
        virtual void rentCar(Car*, int);
        virtual bool hasCar(int);
        virtual void returnCar(int);
        virtual bool isCorporate();
        virtual void print() const;
        virtual ~Customer();
};