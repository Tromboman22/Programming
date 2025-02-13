// Name: Samuel Pineau, Ethan Fadlon 
// ID: 4031432, 40314189

#include "Flight.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// simulate making a new flight object
	cout << "New Flight! Enter a flight ID: ";
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
	f.printinfo();
	return 0;
}
