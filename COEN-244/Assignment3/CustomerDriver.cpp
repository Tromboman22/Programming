//Samuel Pineau, 40317711

#include <iostream>
#include <iostream>
#include <string>
#include <array>
#include "Customer.h"
#include "RegularCustomer.h"
#include "CorporateCustomer.h"
#include "Car.h"
#include "LuxuryCar.h"
#include "StandardCar.h"
#include "Date.h"

using namespace std;

int main()
{
    array<Customer*, 3> customers;
    array<Car*, 5> cars;
    int numcus = 0;
    int numcar = 0;

    //Make some customer objects, corporate and regular
    //Make some car objects as well, luxury and standard
    //Rent some cars for the customers

    Car* car1 = new StandardCar(0);  // Standard Car with ID 0
    Car* car2 = new LuxuryCar(1);    // Luxury Car with ID 1


    Customer* c = new RegularCustomer(numcus++, "Samuel", "Pineau");
    customers[numcus++] = c;
    Customer* c = new RegularCustomer(numcus++, "Antoine", "Beaulieu");
    customers[numcus++] = c;
    Customer* c = new CorporateCustomer(numcus++, "Jason", "Stillman");
    customers[numcus++] = c;


    cout << "Renting cars...\n";
    customers[2]->rentCar(car1, 5);  // Jason rents the first car for 5 days
    customers[1]->rentCar(car2, 3);  // Antoine rents the second car for 3 days

    // Printing the current details of the rented cars and customers
    cout << "\nCustomer Details:\n";
    for(int i = 0; i < 3; i++)
    {
        customers[i]->print();
    }

    // Returning the car rented by Jason
    cout << "\nReturning car rented by Jason...\n";
    customers[2]->returnCar(0);  // Jason returns the car with ID 0

    // Print updated details
    cout << "\nUpdated Customer Details after Jason returns the car:\n";
    customers[2]->print();

    // Clean up dynamically allocated memory
    car1->~Car();
    delete car1;
    car2->~Car();
    delete car2;
    for(int i = 0; i < 3; i++)
    {
        customers[i]->~Customer();
        delete customers[i];
    }

    return 0;

}