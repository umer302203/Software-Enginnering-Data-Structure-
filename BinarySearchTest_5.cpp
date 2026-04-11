#include <iostream>
using namespace std;
int binarySearch(int arr[],int left , int right , int x)
{
while(left<=right)
{
    int mid = left + (right - left)/2;
    if(x == arr[mid])
    {
        return mid;
    }
    else if(x < arr[mid])
    {
        right = mid -1;
    }
    else
    {
        left = mid +1;
    }
}
return -1;
}
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 23; 

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1) {
        cout << "Element is not present in array" << endl;
    } else {
        cout << "Element is present at index " << result << endl;
    }

    return 0;
}
