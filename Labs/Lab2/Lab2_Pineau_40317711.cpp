#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Define variables and prompt user for input
    double price;
    int range = 0;
    char type, question;
    cout << "Enter the product price: ";
    cin >> price;
    if (!cin)
    {
        cout << "Price must be a rational number";
        return 0;
    }
    cout << "Enter customer type (A, B or C): ";
    cin >> type;
    // Check the price range
    if (price >= 100 && price <= 300)
        range = 1;
    else if (price > 300)
        range = 2;
    //Type A prices are 5% times 2^range
    if (type == 'A' || type == 'a')
    {
        price *= (1-0.05*pow(2,range));
    }// Customer type B
    else if (type == 'B' || type == 'b')
    {
        if (range == 0)
            price *= 0.97;
        else if (range == 1)
            price *= 0.92;
        else
        {
            cout << "Have you spent more than 500$ in previous purchases? (y/n): ";
            cin >> question;
            if (question == 'Y' || question == 'y')
                price *= 0.8;
            else
                price *= 0.85;
        }  
    }
    // Customer type C only checks for price >= 100$
    else if (type == 'C' || type == 'c')
    {
        if (range == 1)
        {
            cout << "Do you have the loyalty card? (y/n): ";
            cin >> question;
            if (question == 'Y' || question == 'y')
                price *= 0.95;
        }
        else if (range == 2)
        {
            price *= 0.9;
        }
    }
    else
    {
        cout << "Customer type must be A, B or C, not " << type;
        return 0;
    }
    cout << "Your final price is: " << price;
    return 0;
}

