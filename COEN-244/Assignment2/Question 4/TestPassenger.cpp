// Name: Samuel Pineau, Ethan Fadlon
// ID: 4031432, 40314189

#include "Passenger.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main()
{
    //simulate new passenger
    int i = 0;
    string firstName, lastName, address, email;


    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cin.clear();
    cout << "Enter your address : ";
    getline(cin, address);
    cout << "Enter your email: ";
    cin >> email;
    
    stringstream str; //convert id value from counter to string
    str << i;
    string num = str.str();
    //create a custom student id
    string id;
    id.push_back(firstName[0]); 
    id.push_back(lastName[0]); //1st letter of both first name and last name
    for(int j = 3; j > num.length(); j--)
    {
        id = id + '0'; //add '0' so there are 4 numbers in total
    }
    id.append(num); //add number from counter (will count up in university.cpp)
    cout << "\nPassenger ID: " << id << endl;
    cout << "\n";

    Passenger p = Passenger(id, firstName, lastName, address, email);
    p.Print();

    return 0;
}
