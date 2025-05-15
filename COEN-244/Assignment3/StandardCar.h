// Samuel Pineau, 40317711

#pragma once
#include "Car.h"

using namespace std;

class StandardCar: public Car
{
    public:
        StandardCar();
        StandardCar(const int&);
        StandardCar(const StandardCar &);
        void print() const override;
        
};