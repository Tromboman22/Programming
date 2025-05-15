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

void Customer::rentCar(int){};

void Customer::returnCar(int){};

bool Customer::isCorporate(){};

void Customer::print() const{};

Customer::~Customer() = default;    //Default destructor