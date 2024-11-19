#include "charger.h"
#include <iostream>
using namespace std;


Charger::Charger()
{
    type = "";
    power = 0;
    voltage = 0; 
}

//Re-initialize values
Charger::Charger(int volt, double pow, std::string tp)
{
    type = tp;
    power = pow;
    voltage = volt;
}

double Charger::getPower()
{
    return power;
}

int Charger::getVoltage()
{
    return voltage;
}

string Charger::getType()
{
    return type;
}

// Setting the values
string Charger::setType()
{
    string tp;
    cout << "What type of charger are we looking for? ";
    cin >> tp;
    return tp;
}
double Charger::setPower()
{
    double pow;
    cout << "How powerful is it? ";
    cin >> pow;
    return pow;
}
int Charger::setVoltage()
{
    int volt;
    cout << "What is the voltage it uses? ";
    cin >> volt;
    cout << endl;
    return volt;
}

// Evaluating the data
bool Charger::equals(Charger c2)
{
    if(type == c2.getType() && voltage == c2.getVoltage())
        return true;
    return false;
}

int Charger::Level_evaluate()
{
    if(power <= 3.7)
        return 1;
    else if(power <= 22)
        return 2;
    else
        return 3;
}

void Charger::printinfo(Charger c1, Charger c2)
{
    cout << "The two chargers are:\n";
    //First charger
    cout << type << " charger with " << power
    << " kW charging power uses the voltage of "
    << voltage << " volt\n";
    cout << "Level " << c1.Level_evaluate() << " charger" << endl;
    //Second charger
    cout << c2.getType() << " charger with " << c2.getPower()
    << " kW charging power uses the voltage of "
    << c2.getVoltage() << " volt\n";
    cout << "Level " << c2.Level_evaluate() << " charger" << endl;
    //Format
    cout << endl;
}
