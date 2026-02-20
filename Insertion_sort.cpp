#include <iostream>
using namespace std;

int main() {

    int arr[] = {5, 1, 4, 2, 8};
    int size = 5;
    for (int i = 1; i < size; i++) {

        int key = arr[i]; 
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; 
            j = j - 1;
        }
        

        arr[j + 1] = key;
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
