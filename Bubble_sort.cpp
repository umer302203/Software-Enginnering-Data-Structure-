#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n =8;
  int arr[n]={6,7,2,4,4,3,4,5};
  for(int j=0;j<n;j++)
  {
  for(int i=0;i<n-1;i++)
  {
    if(arr[i]>arr[i+1])
    {
        int temp = arr[i];
        arr[i] =arr[i+1];
        arr[i+1]=temp;

    }
  }
  }
  for(int k=0;k<n;k++)
  {
    cout<<arr[k]<<" ";
  }

return 0;





};


