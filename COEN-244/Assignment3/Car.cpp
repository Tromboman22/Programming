// Samuel Pineau, 40317711

#include <string>
#include <iostream>
#include "Car.h"

using namespace std;

Car::Car(){};

Car::Car(int num, const string& tp, bool fg, bool lux, int prc) : number(num), type(tp), flag(fg), luxury(lux), price(prc) {print();};

Car::Car(const Car &c) : number(c.number), type(c.type), flag(c.flag) {};

int Car::getNum(){return number;};

int Car::getPrice(){return price;};

string Car::getType() const {return type;};

void Car::setRentalDates(Date* d1, Date* d2)
{
    delete rentalDate;
    delete returnDate;
    rentalDate = d1;
    returnDate = d2;
};

Date* Car::getRentalDate(){return rentalDate;};

Date* Car::getReturnDate(){return returnDate;};

bool Car::getFlag() const {return flag;};

void Car::setFlag(bool fg)
{
    flag = fg;
    if(fg)
        cout << "Rented a " << type << " car\n";
    else
        cout << "Returned a " << type << " car\n";
};

void Car::print() const {
    cout << "ID num: " << number
    << ", Type: " << type 
    << ", Rental status: " << flag << endl;
};

Car::~Car()
{
    delete rentalDate, returnDate;
}; 