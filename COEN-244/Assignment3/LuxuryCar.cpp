// Samuel Pineau, 40317711

#include <iostream>
#include "Car.h"
#include "LuxuryCar.h"
 
LuxuryCar::LuxuryCar() : Car::Car(){print();};

LuxuryCar::LuxuryCar(const int& num) : Car::Car(num, "Luxury Car", false, true, 120){};

LuxuryCar::LuxuryCar(const LuxuryCar &s) : Car::Car(s){};

void LuxuryCar::print() const {
    cout << "Luxury Car,   "
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