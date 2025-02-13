// Name: Samuel Pineau
// ID: 4031432

#include "Passenger.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
    //simulate new passenger

    string id, firstName, lastName, address, email;

    cout << "Choose your passenger id: ";
    cin >> id;
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cin.clear();
    cout << "Enter your address : ";
    getline(cin, address);
    cout << "Enter your email: ";
    cin >> email;
    Passenger p = Passenger(id, firstName, lastName, address, email);
    p.Print();

    return 0;
}
