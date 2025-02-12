#include "Room.h"
#include <string>
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

Room::Room(array<int,4>& i)
{
    int in = 0;
    cout << "New Room\n\n";
    while(in < 1 || in > 4)
    {
        cout << "Which floor is it on (1, 2, 3 or 4): ";
        cin >> in;
        //check for errors
        if(cin.fail()) //input isn't integer
        {
            cin.clear();
            cin.ignore(10000, '\n'); 
            cout << "Invalid input, please enter an integer\n";
            continue;
        }
        else if(in < 1 || in > 4)
            cout << "Enter a floor from 1 to 4 please" << endl;
    }   
    id = to_string(in);
    //create a custom Room id
    i[in]++; //Update counter by reference
    if(id.length() < 2) //format length, including a 0 for the first ten rooms
        id = id + '0'; 
    id.append(to_string(i[in])); //add number from counter 
    printinfo();
    cout << endl;
};
string Room::getid()
{
    return id;
};
int Room::getcapacity()
{
    return capacity;
};
void Room::printinfo()
{ 
    cout << "Room ID: " << getid() << endl
    << "Room capacity: " << getcapacity() << " students" << endl;
};