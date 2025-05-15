// Samuel Pineau, 40317711

#pragma once
#include "Car.h"

using namespace std;

class LuxuryCar: public Car
{
    private:

    public:
        LuxuryCar();
        LuxuryCar(const int&);
        LuxuryCar(const LuxuryCar &);
        void print() const override;
};