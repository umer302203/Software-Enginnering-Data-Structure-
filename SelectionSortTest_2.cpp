#include <iostream>
#include <utility>
using namespace std;
void SelectionSort(int arr[], int n)
{
    for(int i = 0 ; i < n ; i++)
    {
   int min = i;
   for(int j = i+1 ; j< n ;j++)
   {
    if(arr[j]< arr[min])
    {
        min = j;
    }
   }
   std::swap(arr[i], arr[min]);
    }
}
int main()
{
    int arr[] = {8 , 9 , 1 , 3 , 7 , 6 ,0 ,2};
    int n = sizeof(arr)/sizeof(arr[0]);
   SelectionSort(arr,n);
    for(int j = 0 ; j < n ; j++)
    {
        cout<< arr[j]<<" ";
    }
     
}