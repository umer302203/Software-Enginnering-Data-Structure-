

#include <iostream>
using namespace std;
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countingSort(int arr[], int n) {
    
    int max = arr[0];
    for (int i = 1; i < n; i++)
     {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    
    int count[max + 1];

   
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    

  
    int k = 0;


    for (int i = 0; i <= max; i++) {
        
        
        for (int j = 0; j < count[i]; j++) {
            
          
            arr[k] = i;
            
         
            k++;
        }
    }
}

int main() {
    int arr[] = {1, 4, 1, 2, 7, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    countingSort(arr, n);

    cout << "Sorted Array:   ";
    printArray(arr, n);

    return 0;
}
