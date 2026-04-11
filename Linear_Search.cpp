#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {

    for (int i = 0; i < n; i++) {
        
        if (arr[i] == target) {
    
            return i;
        }
    }
   
    return -1;
}

int main() {
    int arr[] = {12, 54, 2, 91, 3, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int result = linearSearch(arr, n, target);
 cout<<result<<endl;
}
