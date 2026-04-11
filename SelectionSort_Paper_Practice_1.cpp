#include <iostream>
#include <utility>
using namespace std;
void selectionsort(int arr[],int n)
{
    for(int outerloop = 0 ; outerloop < n-1 ; outerloop++)
    {
    int min = outerloop;
    //Scanner
    for(int i = outerloop+1 ; i < n ; i++)
    {
        if(arr[i]< arr[min])
        {
            min = i;
        }
        
    }
 std::swap(arr[outerloop],arr[min]);
}

}
int main()
{
    int arr[] = {8 , 9 , 1 , 3 , 7 , 6 ,0 ,2};
    int n = sizeof(arr)/sizeof(arr[0]);
   selectionsort(arr,n);
    for(int j = 0 ; j < n ; j++)
    {
        cout<< arr[j]<<" ";
    }
     
}