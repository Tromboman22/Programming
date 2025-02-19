// Name: Samuel Pineau, Ethan Fadlon
// ID: 4031432, 40314189

#include "Airline.h"
#include "Passenger.h"
#include "Flight.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;


class Passenger;
class Flight;
class Airline;

int main() 
{
    string nm, adrs;
    
    
    cout << "Choose a name for your airline: ";
    getline(cin, nm);
    cout << "What is the address: ";
    getline(cin, adrs);
    Airline COEN = Airline(nm, adrs);
    cout << "Welcome to " << COEN.getName() << "!\n"
    << "We are located at " << COEN.getAddress() << endl;

    while(true)
    {
        //get user input
        cout << "Chose an option: " << endl
        << "1. Add a flight" << endl
        << "2. Remove a flight (enter id)" << endl
        << "3. Search for a flight" << endl
        << "4. Display flights" << endl
        << "5. Display flights by departure city and destination" << endl
        << "Else: exit the program" << endl
        << "Choice: ";

        int in = 0;
        cin >> in;

        if(!cin)
        {
            cout << "Goodbye!";
            COEN.~Airline();
            return 0;
        }

        switch(in)
        {
            case 1: //Add a flight
            {
            	//Ask user to input info for the flight
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

                Flight fl = Flight(id, dep_ct, arr_ct);

                //Adds the flight within the Airline object
                COEN.addFlight(fl);

                break;
            }
            case 2: //Remove a flight by id
            {
                if(!COEN.flightCount())  //Bool flightCount returns true if there are flights in the airline
                {
                    cout << "Add flights before calling\n";
                    break;
                }

                cout << "Remove Flight\n";
                string id;
                cout << "Enter flight ID: ";
                cin >> id; 
                COEN.removeFlight(id);  //Removes flight, increments array and flight count, prints confirmation

                break;
            }
            case 3: //Search for a flight
            {
                if(!COEN.flightCount())  //Bool flightCount returns true if there are flights in the airline
                {
                    cout << "Add flights before calling\n";
                    break;
                }
                cout << "Search for a Flight\n";
                string id;
                cout << "Enter flight ID: ";
                cin >> id;
                if(COEN.searchFlight(id))
                {
                    cout << "Flight exists" << endl;
                }
                else
                {
                    cout << "Flight does not exist" << endl;
                }
                break;
            }
            case 4: //Display flights
            {
                if(!COEN.flightCount())  //Bool flightCount returns true if there are flights in the airline
                {
                    cout << "Add flights before calling\n";
                    break;
                }
                cout << "List of flights:\n";
                COEN.displayFlights();
                break;
            }
            case 5: //Display flights by departure city and destination
            {
                if(!COEN.flightCount())  //Bool flightCount returns true if there are flights in the airline
                {
                    cout << "Add flights before calling\n";
                    break;
                }
                string depct, arrct;
                cout << "Flights by departure city and destination" << endl
                << "Enter the departure city: ";
                cin.clear();                //Clear the buffer to allow getline in case cin was used previously
                cin.ignore(1000, '\n');
                getline(cin, depct);        //This is the dearture city
                cout << "Enter the destination: ";
                getline(cin, arrct);        //This is the destination
                COEN.displayFlightsFromTo(depct, arrct);    //Prints all relevant flights
                break;
            }
            default: //Exit the program
            {
                cout << "Goodbye!";
                COEN.~Airline();
                return 0;
            }
        }
    }
}


/*
Function:
void addFlight(const Flight&);
void removeFlight(string x);
bool searchFlight(string x);                    //Return true if flight exists
void displayFlights();
void displayFlightsFromTo(string x, string y);  //Print by departure and destination
*/
