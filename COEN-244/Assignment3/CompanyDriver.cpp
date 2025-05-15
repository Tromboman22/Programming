//Samuel Pineau, 40317711

#include <iostream>
#include <string>
#include <array>
#include "Car.h"
#include "LuxuryCar.h"
#include "StandardCar.h"
#include "Customer.h"
#include "RegularCustomer.h"
#include "CorporateCustomer.h"
#include "Date.h"
#include "Company.h"

using namespace std;


int main() {
    // Create a base date (e.g., March 27, 2025)
    Date* today = new Date(27, 3, 2025);  

    // Create a company object
    Company company("Pineau Rentals", today);

    // Add cars
    cout << "Adding cars:\n";
    for(int i = 0; i < 10; i++)
    {
        company.newCar();   // Adds a new car (Standard or Luxury)
    }

    // Add customers
    cout << "Adding customers:\n";
    for(int i = 0; i < 5; i++)
    {
        string firstName, lastName;
        cout << "Enter first name for customer: ";
        cin >> firstName;
        cout << "Enter last name for customer: ";
        cin >> lastName;
        company.newCustomer(firstName, lastName); // Adds a customer
    }

    // Print the company details (cars and customers)
    cout << "\nCompany Details:\n";
    company.print();

    // Rent a car to a customer
    int carId, customerId;
    cout << "\nEnter car ID to rent: ";
    cin >> carId;
    cout << "Enter customer ID to rent the car: ";
    cin >> customerId;

    // Assuming `company.isCarid` and `company.isCustomerid` are correct and valid
    if (company.isCarid(carId) && company.isCustomerid(customerId)) {
        Car* car = company.returnCar(carId);
        Customer* customer = company.getCustomer(customerId);
        company.rentCar(car, customer); // Rent the car to the customer
        cout << "Car rented successfully.\n";
    } else {
        cout << "Invalid car or customer ID.\n";
    }

    // Print the updated company details
    cout << "\nUpdated Company Details:\n";
    company.print();


    // Advance to the next day
    cout << "\nDo you want to advance to the next day? (y/n): ";
    char nextDayChoice;
    cin >> nextDayChoice;
    if (nextDayChoice == 'y' || nextDayChoice == 'Y') {
        company.nextDay();
        cout << "The day has been advanced.\n";
    }
    
    // Return a car
    cout << "\nEnter car ID to return: ";
    cin >> carId;
    if (company.isCarid(carId)) {
        Customer* customer = company.getCustomer(customerId); // Assuming the customer returned a valid car
        company.returnCar(customer); // Process car return
        cout << "Car returned successfully.\n";
    } else {
        cout << "Invalid car ID.\n";
    }

    // Print the final company details
    cout << "\nFinal Company Details:\n";
    company.print();

    company.~Company();
    return 0;
}
