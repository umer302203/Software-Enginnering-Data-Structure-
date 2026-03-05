#include <iostream>
using namespace std;


void print_Array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


void shell_sort(int arr[], int n)
{
    
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        
        for (int i = gap; i < n; i++)
        {
    
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
       
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

int main()
{
    int arr[]{12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before Sorting: ";
    print_Array(arr, n); 

    shell_sort(arr, n);

    cout << "Array after Sorting:  ";
    print_Array(arr, n);

    return 0;
}
