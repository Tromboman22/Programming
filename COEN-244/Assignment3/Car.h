// Samuel Pineau, 40317711

#pragma once
#include <string>
#include "Date.h"

using namespace std;

class Car
{
    protected:
        int number;
        string type;
        int price;  //price per day
        bool luxury;
        bool flag;
        Date* rentalDate;
        Date* returnDate;
    
    public:
        Car();
        Car(int, const string&, bool, bool, int);
        Car(const Car &c);
        int getNum();
        virtual int getPrice();
        string getType() const;
        void setRentalDates(Date*, Date*);
        Date* getRentalDate();
        Date* getReturnDate();
        bool getFlag() const;
        void setFlag(bool);
        virtual void print() const;
        virtual ~Car();
};


//constructor (regular and default, copy as well), set+get, print