// Name: Samuel Pineau, Ethan Fadlon 
// id: 4031432, 40314189

#include "Flight.h"
#include "Passenger.h"
#include <iostream>
#include <string>
#include <array>
#include <iomanip>


using namespace std;

int main()
{
	int IDNum = 0; //Used to create unique passenger ID's

	// simulate making a new flight object
	cout << "New Flight! Enter a flight id: ";
	string id, dep_ct, arr_ct;
	cin >> id;

	cout << "Enter a departure city: ";
	//flush buffer
	cin.clear();
	cin.ignore(1000, '\n');
	getline(cin, dep_ct);

	cout << "Enter a destination city: ";
	getline(cin, arr_ct);

	Flight f = Flight(id, dep_ct, arr_ct);


	//Add passengers to the flight
	cout << "Welcome to Flight " << id << " from " << dep_ct << " to " << arr_ct << endl;

	
	while (true)
	{
		// get user input
		cout << "1. Add a passenger" << endl
			<< "2. Remove a passenger" << endl
			<< "3. Search a passenger" << endl
			<< "4. Display passengers" << endl
			<< "Else: Exit the program" << endl
			<< "Choice: ";

		int in = 0;
		cin >> in;

		if (!cin)
		{
			cout << "Goodbye!";
			f.~Flight();
			return 0;
		}

		switch(in)
		{
			case 1: // Add a passenger
			{

				string firstName, lastName, address, email;

				cout << "New passenger\n";
				cout << "Enter your first name: ";
				cin >> firstName;
				cout << "Enter your last name: ";
				cin >> lastName;
				cin.clear();
				cout << "Enter your address : ";
				getline(cin, address);
				cout << "Enter your email: ";
				cin >> email;
				
				stringstream str; //convert integer IDNum value from to string for passenger ID
				str << IDNum;
				string num = str.str();

				//create a custom passenger id
				string id;
				id.push_back(firstName[0]); 
				id.push_back(lastName[0]); // Use 1st letter of both first name and last name to make custom ID
				for(int j = 3; j > num.length(); j--)
				{
					id = id + '0'; //add '0' so there are 4 numbers in total
				}
				id.append(num); //add number from counter (will count up in university.cpp)
				cout << "\nPassenger ID: " << id << endl;
				cout << "\n";

				Passenger p = Passenger(id, firstName, lastName, address, email);
				IDNum++;

				f.addPassenger(p);
				break;
			}
			case 2: // Remove a passenger
			{
				cout << "Remove a passenger\n Enter the passenger id: ";
				string id;
				cin >> id;
				f.removePassenger(id);
				break;
			}
			case 3: // Search for a passenger
			{
				cout << "Search for a passenger\n Enter the passenger id: ";
				string id;
				cin >> id;
				if(f.searchPassenger(id))
				{
					cout << "Passenger is in flight\n";
				}
				else{
					cout << "Passenger not found\n";
				}
				break;
			}
			case 4: // Display passengers
			{
				cout << "Displaying passengers: " << endl;
				f.displayPassenger();
				break;
			}
			default: // Exit the program
			{
				cout << "Goodbye!";
				f.~Flight();
				return 0;
			}
		}
	}
}
