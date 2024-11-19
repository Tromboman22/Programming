#include "charger.h"
#include <iostream>
#include <string>

int main()
{
    //Define chargers
    Charger c1(c1.setVoltage(), c1.setPower(), c1.setType());
    Charger c2(c2.setVoltage(), c2.setPower(), c2.setType());
    //Print info and levels
    c1.printinfo(c1, c2);
    //Check if equal
    std::cout << "Are the 2 chargers exchangeable?\n";
    if(c1.equals(c2))
        std::cout << "Yes";
    else
        std::cout << "No";
}