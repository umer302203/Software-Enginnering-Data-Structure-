#include <iostream>
using namespace std;
int linearsearch(int arr[],int target,int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
        
    }
return -1;
}
int main() {
    int arr[] = {12, 54, 2, 91, 3, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;
    int result = linearsearch(arr , n ,target); 
    if (result == -1) {
        cout << "Element not found." << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }
}