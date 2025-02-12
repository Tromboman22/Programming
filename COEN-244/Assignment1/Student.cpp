#include "Student.h"
#include "CourseSection.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

Student::Student(int i){ //Define student attributes
    cout << "Create new student profile\n\nEnter Name: ";
    name = setname();
    cout << "Enter Surname: ";
    surname = setsurname();
    cout << "Enter address: ";
    address = setaddress();
    cout << "Enter email: ";
    email = setemail();
    stringstream str; //convert id value from counter to string
    str << i;
    string num = str.str();

    //create a custom student id
    id.push_back(name[0]); 
    id.push_back(surname[0]); //1st letter of both name and surname
    for(int j = 4; j > num.length(); j--)
    {
        id = id + '0'; //add '0' so there are 4 numbers in total
    }
    id.append(num); //add number from counter (will count up in university.cpp)
    cout << "\nStudent ID: " << id << endl;
    cout << "\n";
};
//get and set functions
string Student::getid(){
    return id;
};
string Student::getname(){
    return name;
};
string Student::getsurname(){
    return surname;
};
string Student::getaddress(){
    return address;
};
string Student::getemail(){
    return email;
};
string Student::setname(){
    string in;
    cin >> in;
    return in;
};
string Student::setsurname(){
    string in;
    cin >> in;
    return in;    
};
string Student::setaddress(){
    string in;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //while using both getline() and cin in the same code clear cin
    getline(cin, in); //getline for both street name and house address
    return in;
};
string Student::setemail(){
    string in;
    cin >> in;
    return in;
};
void Student::addcourse(CourseSection* cs)
{
    courses.push_back(cs);
};
bool Student::istaken(CourseSection* cs)
{
    for(int i = 0; i < courses.size(); i++)
    {
        if(courses[i]->getid() == cs->getid())
            return true;
    }
    return false; //course not taken
};
void Student::printinfo(){ //print all private attributes
    cout << "Student info:\nID: " << getid() << endl
    << "Name: " << getname() << endl
    << "Surname: " << getsurname() << endl
    << "Address: " << getaddress() << endl
    << "Email: " << getemail() << endl;
};