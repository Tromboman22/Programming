#pragma once
#include <string>
class Charger {
    private:
        std::string type;
        double power;
        int voltage;

    public:
        Charger();
        Charger(int volt, double pow, std::string tp);
        //Access data
        double getPower();
        int getVoltage();
        std::string getType();
        //User input 
        double setPower();
        int setVoltage();
        std::string setType();
        //Evaluating 
        bool equals(Charger c2);
        int Level_evaluate();
        void printinfo(Charger c1, Charger c2);
};