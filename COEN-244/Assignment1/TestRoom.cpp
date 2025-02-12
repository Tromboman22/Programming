#include "Room.h"
#include <iostream>
#include <array>


int main()
{
    array<int, 4> counter = {0,0,0,0}; //counter for room numbers per floor
    Room test1 = Room(counter);
    Room test2 = Room(counter);
    Room test3 = Room(counter);
    Room test4 = Room(counter);
    test1.printinfo();
    test2.printinfo();
    test3.printinfo();
    test4.printinfo();
    return 0;
}