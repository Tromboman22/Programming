#include <iostream>
using namespace std;

int main(){
    //Prime number
    int prime;
    cout << "Enter a prime number: ";
    cin >> prime;
    int check = 0;

    //Check 1st number
    for(int j = 2; j < prime/2 + 1; j++){
            //Check until last possible divider at i/2
            if(prime%j == 0)
                check = 1;
    }
    if (check == 1)
    {
        cout << "Enter a valid prime number";
        return 0;
    }else{
        cout << prime << endl;
    }

    for(int i = prime-1; i > 1; i--){ 
        int check = 0;
        for(int j = 2; j < i/2 + 1; j++){
            //Check until last possible divider at i/2
            if(i%j == 0)
                check = 1;
        }
        //If there is no divider
        if (check == 0)
            cout << i << endl;
    }
    return 0;
}