#include <iostream>
#include <array>
#include <string>

using namespace std;


int get_summation(array <int, 10> arr, int in);

int main(){
    cout << "Please enter 10 integers: ";
    array <int, 10> nums;
    for (int i = 0; i < 10; i++)
    {
        cin >> nums[i]; //prompt for 10 integers
    }
    cout << "You entered the following list of integers:\n"; //format first output
    for (int i = 0; i < 10; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    array <int, 5> temp; //define final output array

    for(int j = 0; j<5; j++){
        temp[j] = get_summation(nums, j); 
    }

    //Output:
    cout << "Result after processing array is: ";
    for(int k = 0; k < 5; k++)
        cout << temp[k] << " ";

    return 0;
}

int get_summation(array <int, 10> arr, int in)
{
    return(arr[in] + arr[9-in]); //adds first and last digits together
}