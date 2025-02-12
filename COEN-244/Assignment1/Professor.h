#pragma once
#include <string>

using namespace std;

class Professor{
    private:
        string id;
        string name;
        string surname;
        string address;
        string email;

    public:
        Professor(int i);
        string getid();
        string getname();
        string getsurname();
        string getaddress();
        string getemail();
        string setname();
        string setsurname();
        string setaddress();
        string setemail();
        void printinfo();
};
