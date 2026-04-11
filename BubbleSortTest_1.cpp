#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    for (int outerloop = 0; outerloop < n - 1; outerloop++)
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
int main()
{
    int arr[] = {8 , 9 , 1 , 3 , 7 , 6 ,0 ,2};
    int n = sizeof(arr)/sizeof(arr[0]);
   bubbleSort(arr,n);
    for(int j = 0 ; j < n ; j++)
    {
        cout<< arr[j]<<" ";
    }
     
}