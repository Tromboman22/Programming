// Samuel Pineau, 40317711

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
#include "Company.h"

using namespace std;



Company::Company(){};

Company::Company(string nm, Date* base) : name(nm), baseDate(base){};

Company::Company(const Company& c) : name(c.name), baseDate(c.baseDate), carid(c.carid), custid(c.custid), numCars(c.numCars), numCust(c.numCust) {};

void Company::newCar(){cars[numCars++] = addCar();};

Car* Company::addCar() //Fill up Cars array
{
    cout << "1. Standard car, 2. Luxury car\nInput: ";
    int in;
    cin >> in;
    if(in == 1)
    {
        Car* n = new StandardCar(carid++);
        numCars++;
        return n;
    }
    else if(in == 2)
    {
        Car* n = new LuxuryCar(carid++);
        numCars++;
        return n;
    }
    else    //Non compliant input
    {
        cout << "Invalid input\n";
        return addCar();    //Car* addCar() - recursion to restart the fuction
    }

};      

void Company::newCustomer(string fnm, string lnm){customers[numCust++] = addCustomer(fnm, lnm);};

Customer* Company::addCustomer(string fnm, string lnm)
{
    cout << "1. Regular customer, 2. Corporate customer\nInput: ";
    int in;
    cin >> in;
    if(in == 1)
    {
        Customer* c = new RegularCustomer(custid++, fnm, lnm);
        numCust++;
        return c;
    }
    else if(in == 2)
    {
        Customer* c = new CorporateCustomer(custid++, fnm, lnm);
        numCust++;
        return c;
    }
    else    //Non compliant input
    {
        cout << "Invalid input\n";
        return addCustomer(fnm, lnm);    //Customer* addCustmoer() - recursion to restart the fuction
    }
};    //Fill up customer array

void Company::rentCar(Car* vh, Customer* prs)  //Rent to customer
{
    if(vh->getFlag())   //is rented?
    {
        cout << "Car already rented..." << endl;
        return;
    }
    else if(prs->getNumRents() > 9)
    {
        cout << "Maximum number of rentals exceeded..." << endl;
        return;
    }
    //Rent for Customer and add rental dates in Car
    int in;
    //Set dates
    Date* copy1 = new Date(*baseDate);
    Date* copy2 = new Date(*baseDate);

    cout << "Today is ";
    baseDate->printDate();
    cout << "Number of days to rent the car for: ";
    cin >> in;
    prs->rentCar(vh, in);
    if(in > 0)
    {
        copy2->addDays(in);
    }
    vh->setRentalDates(copy1, copy2);
    
};

void Company::returnCar(Customer* prs)      //Car returned
{
    int in;
    while(true)
    {
        cout << "Enter car ID or negative number to exit: ";
        cin >> in;
        if(in < 0)
            return;
        else if(prs->hasCar(in))
        {
            break;
        }
        else    
            cout << "Invalid ID number. ";
    }
    prs->returnCar(in);
};

bool Company::isCustomerid(int in)     //Check tfor valid id
{
    for(int i = 0; i < numCust; i++)
    {
        if(in == customers[i]->getid())
            return true;
    }
    return false;
};

Customer* Company::getCustomer(int in)
{
    //Call if isCustomerid() returns true
    for(int i = 0; i < numCust; i++)
    {
        if(in == customers[i]->getid())
            return customers[i];
    }
};    

bool Company::isCarid(int in)      //Check for valid id
{
    for(int i = 0; i < numCars; i++)
    {
        if(in == cars[i]->getNum())
            return true;
    }
    return false;    
};
Car* Company::returnCar(int in)
{
    //Call if isCarid() returns true
    for(int i = 0; i < numCars; i++)
    {
        if(in == cars[i]->getNum())
            return cars[i];
    }
};

void Company::nextDay()     //Go to next day
{
    baseDate->addDays(1);
};        

void Company::print()
{
    cout << "Company name: " << name << endl;

    cout << "Cars: \n";
    for(int i = 0; i < numCars; i++)
        cars[i]->print();

    cout << endl << "Customers: \n";
    for(int i = 0; i < numCust; i++)
        customers[i]->print();
};

Company::~Company()     //Destructor
{
    for(int i = 0; i < numCars; i++)
    {
        cars[i]->~Car();
        delete cars[i];
    }
    
    for(int i = 0; i < numCust; i++)
    {
        customers[i]->~Customer();
        delete customers[i];
    }
    delete baseDate;
};