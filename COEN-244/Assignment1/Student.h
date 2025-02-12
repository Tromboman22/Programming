#pragma once
#include "CourseSection.h"
#include <string>
#include <vector>

using namespace std;

class CourseSection;

class Student{
    private:
        string id;
        string name;
        string surname;
        string address;
        string email;
        vector <CourseSection*> courses;
        

    public:
        Student(int i);
        string getid();
        string getname();
        string getsurname();
        string getaddress();
        string getemail();
        string setname();
        string setsurname();
        string setaddress();
        string setemail();
        void addcourse(CourseSection* cs);
        bool istaken(CourseSection*);
        void printinfo();
};

