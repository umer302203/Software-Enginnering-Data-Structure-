#include <iostream>
using namespace std;
 void merge(int arr[] , int L , int mid , int R)
 {
    //Phla size dakhna ha
    int n1  = mid - L+1,n2 = R-mid;
    //Pher ab temp array bana or us ma size do
    int LA[n1],RA[n2];
    //Ab inha bhar do
 for(int i = 0 ; i<n1 ; i++)
 {
  LA[i] = arr[L+i];
 }
 //Ab right wala bhi bhar dia ha
 for(int j = 0 ; j< n2 ; j++)
 {
    RA[j] = arr[mid+j];
 }
 //Ab in tesno LA RA or original ma sa slect karna k liya banao selector taka compare kar saga
 int i = 0;
 int j = 0;
 int k = L; //Original array k liya ha L yani 0 ya us waqat jo ho ga wahas sa sharu ho ga


 //Ab orignail array ma save karna ha compare kar k
 while(i<n1&&j<n2)
 {
    if(LA[i]<=RA[j])
    {
        arr[k] = LA[i++];
    }
    else
    {
        arr[k] = RA[j++];
        k++;
    }
 }
 while(i < n1)
 {
    arr[k] = LA[i];
    i++;
    k++;
 }
 while( j < n2)
 {
    arr[k] = RA[j];
    j++;
    k++;
 }

 }
 void MergeSort(int arr[] , int L ,int R)
 {
    if(L<=R)
 {
    
    return;
    int mid = L+(R-L)/2;
    MergeSort(arr , L , mid-L+1 );
    MergeSort(arr , mid+1 , R);
    merge(arr , L ,mid ,R);
 }
 }




int main()
{
  int n =8;
  int arr[10]={1,5,6,2,7,3,7,8,9};
  MergeSort(arr,0,n-1);
  for(int k =0;k<n;k++)
  {
      cout<<arr[k];
  }
  }
