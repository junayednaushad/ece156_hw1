#include <iostream>
using namespace std;

int min(int* arr, int length)
{
    int min = arr[0];
    for(int i = 1; i < length; i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}

int max(int* arr, int length)
{
    int max = arr[0];
    for(int i = 1; i < length; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

int avg(int* arr, int length)
{
    int sum = 0;
    for(int i = 0; i < length; i++)
    {
        sum += arr[i];
    }
    return sum/length;
}


int main()
{
    int nums[5] = {3,7,12,5,6};
    int minimum = min(nums, 5);
    int maximum = max(nums, 5);
    int average = avg(nums, 5);
    cout << minimum << endl << maximum << endl << average << endl;
    return 0;
}
