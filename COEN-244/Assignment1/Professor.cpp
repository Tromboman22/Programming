#include "Professor.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

//Copied code from Student.cpp and changed to professor except for length of id

Professor::Professor(int i){ //Define Professor attributes
    cout << "Create new Professor profile\nEnter Name: ";
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

    //create a custom Professor id
    id.push_back(name[0]); 
    id.push_back(surname[0]); //1st letter of both name and surname
    for(int j = 3; j > num.length(); j--)
    {
        id = id + '0'; //add '0' so there are 3 numbers in total
    }
    id.append(num); //add number from counter (will count up in university.cpp)
    cout << getid() << endl << "\n";
};
//get and set functions
string Professor::getid(){
    return id;
};
string Professor::getname(){
    return name;
};
string Professor::getsurname(){
    return surname;
};
string Professor::getaddress(){
    return address;
};
string Professor::getemail(){
    return email;
};
string Professor::setname(){
    string in;
    cin >> in;
    return in;
};
string Professor::setsurname(){
    string in;
    cin >> in;
    return in;    
};
string Professor::setaddress(){
    string in;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //while using both getline() and cin in the same code clear cin
    getline(cin, in); //getline for both street name and house address
    return in;
};
string Professor::setemail(){
    string in;
    cin >> in;
    return in;
};
void Professor::printinfo(){ //print all private attributes
    cout << "ID: " << getid() << endl
    << "Name: " << getname() << endl
    << "Surname: " << getsurname() << endl
    << "Address: " << getaddress() << endl
    << "Email: " << getemail() << endl;
};

