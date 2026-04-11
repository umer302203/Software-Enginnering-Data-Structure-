#include <iostream>
using namespace std;
int binarySearch(int arr[],int left , int right ,  int target)
{
    
    while(left <= right)
    {
       int  mid = left+(right - left)/2;
       if(target<arr[mid])
       {
      right = mid - 1;
       }
       else if(target>arr[mid])
       {
left = mid+1;
       }
       else
       {
        return mid;
       }
    }
    return -1;
}
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 56; 

    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1) {
        cout << "Element is not present in array" << endl;
    } else {
        cout << "Element is present at index " << result << endl;
    }

    return 0;
}
