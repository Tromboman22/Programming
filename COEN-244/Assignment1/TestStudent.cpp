#include "Student.h"
#include <iostream>


int main()
{
    int counter = 1;
    Student test = Student(counter++);
    test.printinfo();
    return 0;
}