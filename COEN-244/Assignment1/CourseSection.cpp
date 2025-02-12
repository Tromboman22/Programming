#include "CourseSection.h"
#include "Room.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <array>

using namespace std;

CourseSection::CourseSection(int i)
{
    cout << "New Course Section\n\nEnter course title: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clears input buffer
    getline(cin, title);
    cout << "Enter a description: ";
    getline(cin, description);
    //create a custom course id
    stringstream str; //convert id value from counter to string
    str << i;
    string num = str.str();
    for(int j = 0; j < 3; j++)//add first 3 letters of course section in id
    {
        id.push_back(toupper(title[j]));
    }
    for(int i = 4; i > num.length(); i--)
    {
        id = id + '0'; //add '0' so there are 4 numbers in total
    }
    id.append(num); //add number from counter (will count up in university.cpp)
    cout << getid() << endl << "\n";
};
string CourseSection::getid()
{
    return id;
};
string CourseSection::gettitle()
{
    return title;
};
string CourseSection::getdescription()
{
    return description;
};
int CourseSection::getcapacity()
{
    return capacity;
};
void CourseSection::printinfo()
{
    cout << "Course ID: " << getid() << endl
    << "Title: " << gettitle() << endl
    << "Description: " << getdescription() << endl
    << "Course capacity: " << getcapacity() << " students" << endl;
};