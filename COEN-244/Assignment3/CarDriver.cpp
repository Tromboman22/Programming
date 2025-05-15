// Samuel Pineau, 40317711

#include <iostream>
#include <array>
#include "Car.h"
#include "LuxuryCar.h"
#include "StandardCar.h"
#include "Date.h"

using namespace std;

int main()
{
    int id = 0;
    int prompt;
    char q;
    array<Car*, 10> cars;
    

    cout << "Car class test\n";

    //Add cars in cars array
    while(id < 10)
    {
        cout << "Standard car (1) or luxury car (2): ";
        cin >> prompt;
        if(prompt == 1)
        {
            Car* c = new StandardCar(id);
            cars[id++] = c;
        }
        else if(prompt == 2)
        {
            Car* c = new LuxuryCar(id);
            cars[id++] = c;
        }
        else
        {
            break;
        }
        
    }

    //Rent cars
    while(id > 0)
    {
        cout << "Rent a car? (y or n)";
        cin >> q;

        if(q == 'y')
        {
            cout << "Enter car ID: ";
            cin >> prompt;

            //error handling
            if(prompt >= id || prompt < 0)
            {
                cout << "Invalid ID\n";
                continue;
            }

            //Set rantal status
            for(int i = 0; i < id; i++)
            {
                if(cars[i]->getNum() == prompt)
                {
                    cars[i]->setFlag(!cars[i]->getFlag());
                }
            }
        }
        else
        {
            break;
        }
    }


    cout << "List of cars:\n";
    for(int i = 0; i < id; i++)
    {
        cars[i]->print();   //Override func
        cars[i]->~Car();    //Destructor
    }
    cout << "Freed the memory\n";
    cout << "Exiting program, thank you!";
    return 0;
}