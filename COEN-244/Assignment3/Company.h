// Samuel Pineau, 40317711
#pragma once

#include <iostream>
#include <string>
#include <array>
#include "Car.h"
#include "LuxuryCar.h"
#include "StandardCar.h"
#include "Customer.h"
#include "RegularCustomer.h"
#include "CorporateCustomer.h"
#include "Date.h"

using namespace std;


class Company
{
    private:
        Date* baseDate;                 //What day is today
        string name;                    //Company name
        int carid = 0;                     //Automatic ID generation cars
        int custid = 0;                 //Customer ID generation
        int numCars = 0, numCust = 0;   //Keep track of array sizes
        array<Car*, 1000> cars;         //Hold pointers for all cars and customer it is rented to
        array<Customer*, 50> customers; //Array of customer objects

    public:
        Company();
        Company(string, Date*);
        Company(const Company&);
        void newCar();
        Car* addCar();              //Fill up Cars array
        void newCustomer(string, string);
        Customer* addCustomer(string, string);    //Fill up customer array
        void rentCar(Car*, Customer*);  //Rent to customer
        void returnCar(Customer*);      //Car returned
        bool isCustomerid(int);     //Check tfor valid id
        Customer* getCustomer(int);    
        bool isCarid(int);          //Check for valid id
        Car* returnCar(int);
        void nextDay();             //Go to next day
        void print();
        ~Company();             //Destructor
};


//cars array, company name