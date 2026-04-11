#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int outerloop = 0; outerloop < n - 1; outerloop++)
    {

        {
            for (int innerloop = 0; innerloop < n - 1; innerloop++)
            {
                if (arr[innerloop] > arr[innerloop + 1])
                {
                    int temp = arr[innerloop];
                    arr[innerloop] = arr[innerloop + 1];
                    arr[innerloop + 1] = temp;
                }
            }
        }
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array is: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted array is: ";
    printArray(arr, n);

    return 0;
}