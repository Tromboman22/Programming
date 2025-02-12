#pragma once
#include <string>
#include <array>
#include "Student.h"
#include "Room.h"

using namespace std;

class CourseSection{
    private:
        string id;
        string title;
        string description;
        static const int capacity = 100;

    
    public: 
        CourseSection(int i);
        string getid();
        string gettitle();
        string getdescription();
        int getcapacity();
        void printinfo();
};

