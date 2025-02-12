#pragma once
#include <string>
#include <array>

using namespace std;

class Room{
    private:
        string id;
        static const int capacity = 120;
    
    public: 
        Room(array<int, 4>& i);
        string getid();
        int getcapacity();
        void printinfo();
};

