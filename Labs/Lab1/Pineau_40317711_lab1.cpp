#include <iostream>
using namespace std;


int main(){
    //Define Prices
    double fuji_price =2, golden_price =6, red_price = 5;
    //Assign counts
    int fuji_count, golden_count, red_count;
    double total;

    //Apple count (fuji, golden, red)
    cout << "Number of fuji apples: ";
    cin >> fuji_count;

    cout << "Number of golden apples: ";
    cin >> golden_count;

    cout << "Number of red apples: ";
    cin >> red_count;

    //Calculating the total
    total = fuji_count * fuji_price + golden_count * golden_price + red_count * red_price;

    //Bonus apples
    int bonus = golden_count/5;

    cout << "Your total bill for " << fuji_count << " fuji apple(s), " << golden_count << " golden apple(s), and "<<red_count<< " red apple(s) is $" << total<<". You have earned "<<bonus<<" free golden apple(s).";
    return 0;   
}