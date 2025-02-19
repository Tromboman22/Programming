// Name: Samuel Pineau, Ethan Fadlon
// ID: 4031432, 40314189

#include "Flight.h"
#include "Date.h"
#include "Time.h"
#include <iostream>
#include <string>
using namespace std;

Flight::Flight()                //Default constructor
{
    id = "";
};
Flight::Flight(string x, string dep, string arriv)
{
    id = x;
    departureCity = dep;
    arrivalCity = arriv;


    //defining both date parameters

    int a, b, c, d, e, f;

    cout << "Enter the date (numbers) of departure (day, month, year): ";
    //catch exceptions
    while(!(cin >> a >> b >> c) || !checkDate(a, b, c))
    {
        cout << "Invalid input!\ntip: integers only\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << "Enter the time of departure (hour, minute, second): ";

    while (!(cin >> d >> e >> f))
    {
		cout << "Invalid input!\ntip: integers only\n";
		cin.clear();
		cin.ignore(1000, '\n');
    }
    int day = a;
    float deptm = d + e / 60 + f/3600; //used to calculate duration
    departureDate = new Date(a, b, c, d, e, f);

    //flush the buffer if user wrote more than six inputs
    cin.ignore(1000, '\n');

    cout << "Enter the date (numbers) of arrival (day, month, year): ";
    //catch exceptions
    while (!(cin >> a >> b >> c) || !checkDate(a, b, c))
    {
        cout << "Invalid input!\ntip: integers only\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << "Enter the time of arrival (hour, minute, second): ";
    while (!(cin >> d >> e >> f))
    {
        cout << "Invalid input!\ntip: integers only\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    float arrtm = d + e / 60 + f / 3600; //used to calculate duration
    arrivalDate = new Date(a, b, c, d, e, f);

    cin.ignore(1000, '\n'); //flush again just in case

    //define flight duration
    cout << "Enter the time zone difference (-11 to 12 hours): ";
    while (!(cin >> duration) || duration > 12 || duration < -11)
    {
        cout << "Invalid input\n";
    }
    //add the time difference to the jet lag
    duration = -(duration) + arrtm - deptm;

    //add a day if you arrive on a new day
    if (a != day)
        duration += 24;
    cout << "Expected flight duration: " << duration  << " hours" << endl;
};
Flight::Flight(const Flight & fl)  //copy constructor
{
    id = fl.id;
    departureCity = fl.departureCity;
    arrivalCity = fl.arrivalCity;
    departureDate = fl.departureDate;
    arrivalDate = fl.arrivalDate;
    duration = fl.duration;
}; 
string Flight:: getID()
{
    return id;
};
string Flight:: getDepCity()
{
    return departureCity;
};
string Flight:: getArrCity()
{
    return arrivalCity;
};
Date Flight:: getDepDate()
{
    return *departureDate;
};
Date Flight:: getArrDate()
{
    return *arrivalDate;
};
int Flight:: getDuration()
{
    return duration;
};
void Flight:: printinfo()
{
    cout << "ID: " << id << endl
    << "Departure City: " << departureCity << " on "; 
    departureDate->printDate(); 
    cout << "Arrival City: " << arrivalCity << " on ";
    arrivalDate->printDate();
    cout  << "Expected flight duration: " << duration  << " hours" << endl;
};
bool Flight::checkDate(int x, int y, int z)
{
    //x is the day
    //y is the month
    //z is the year
    bool check = true; 

    if (y < 0 || y > 12)    // check if the month is in range
    {
        cout << "Month must be from 1 to 12\n";
        check = false;
    }

    if (y==1||y==3||y==5||y==7||y==8||y==10||y==12) //checking months with only 31 days.
    {
        if (x < 1) 
        {
            cout << "Months cannot have less than 1 day.\n";
            check = false;
        }

        if (x > 31)
        {
            cout << "This month cannot have more than 31 days\n";
            check = false;
        }
    }

	if (y == 4 || y == 6 || y == 9 || y == 11) //checking months with 30 days.
	{
		if (x < 1)
		{
			cout << "Months cannot have less than 1 day.\n";
			check = false;
		}

        if (x > 30)
        {
            cout << "This month cannot have more than 30 days\n";
            check = false;
        }
	}

    if (y==2) //checking months with 29 days.
    {
		if (x < 1)
		{
			cout << "Months cannot have less than 1 day.\n";
			check = false;
		}

		if (x > 29)
		{
			cout << "This month cannot have more than 29 days\n";
			check = false;
		}
    }

    if (z<2025) //validating present and future flights
    {
        cout << "Flight date must be in the year 2025 or greater\n";
		check = false;
    }
    return check;
};
Flight::~Flight()   //Destructor
{
    delete arrivalDate->time;
    delete arrivalDate;
    delete departureDate->time;
    delete departureDate;
    for(int i = 0; i < seatCount; i++) //delete all the passengers from the flight
    {
        delete seats[i];
    }
};

//Functions unique to Q4.
void Flight::addPassenger(const Passenger& pass)  //Add a passenger 
{
	//add a passenger at seats[seatCount]
    if(seatCount < 100)
    {
        Passenger* p = new Passenger(pass);
        seats[seatCount] = p;
        seatCount++;
    }
	
};
void Flight::removePassenger(string z) 
{
    //Delete the passenger at the right ID
	//decrement the seat count 
    //replace every seat
    bool check = false;
    for(int i = 0; i < seatCount; i++)
    {       
        if (seats[i]->getID() == z)
        {
            check = true;
            seatCount--;
            delete seats[i];
        }
        if(check)
        {
            seats[i] = seats[i + 1];
            delete seats[i + 1];
        }
    }
    if(!check)
    {
        cout << "Invalid id" << endl;
    }
}
bool Flight::searchPassenger(string z) 
{ 
	for (int i = 0; i < 100; i++)
	{
		if (seats[i]->getID() == z )
        {
            return true;
        }
	}
	return false;
}
void Flight::displayPassenger() 
{ 
	for (int i = 0; i < seatCount; i++)
	{
		seats[i]->Print();
        cout << endl;
	}
}
