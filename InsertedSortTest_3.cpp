#include <iostream>
#include <utility>
using namespace std;

void InsertionSort(int arr[], int n)
{
for(int unsorted = 1 ; unsorted < n ; unsorted++)
{
    int sorted =unsorted -1;
    int key = arr[unsorted];
    while(sorted >= 0 && key < arr[sorted])
    {
        //Unsorted sa pichla hisa ma phala number ko aga shift karta ha
    arr[sorted+1] = arr[sorted];
    //Sorted hisa ma sa jo khali jaga banti ha us sa pichal wala hisa per ungli rakhta ha
    sorted = sorted - 1;
    }
arr[sorted+1]= key;
}

}
int main()
{
    int arr[] = {8 , 9 , 1 , 3 , 7 , 6 ,0 ,2};
    int n = sizeof(arr)/sizeof(arr[0]);
   InsertionSort(arr,n);
    for(int j = 0 ; j < n ; j++)
    {
        cout<< arr[j]<<" ";
    }
     
}