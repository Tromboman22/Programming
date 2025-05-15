// Samuel Pineau, 40317711

#include <string>
#include <iostream>
#include "Car.h"
#include "StandardCar.h"

StandardCar::StandardCar() : Car::Car(){print();};

StandardCar::StandardCar(const int& num) : Car::Car(num, "Standard Car", false, false, 70){};

StandardCar::StandardCar(const StandardCar &s) : Car::Car(s){};

void StandardCar::print() const{
    cout << "Standard Car, "
    << "ID: " << number
    << ", Rental Status: ";
    if(flag)
        {
            cout << "Renting from "; 
            rentalDate->printDate();
            cout << " to ";
            returnDate->printDate();
            cout << endl;
        }
    else
        cout << "Ready to rent\n";
};