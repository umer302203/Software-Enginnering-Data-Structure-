#include <iostream>
using namespace std;
/*Ab hum ik function banaya ga jo bataya ga k array ma sa sab sa bara elemnt kon sa ha taka us k mutabaik rund jasa agr sab sa bara number 2 digit
wala ha t mtlb 2 round tak agr 3 ha to mtlb 3 round jasa phala round 1 dusra 10 tesra 100 asa */
int getMax(int arr[],int n)
//Phala hum ya samjaga ga k index 0 per  sab sa bara elemnt ha pher is liya 0 k brabar rakha ga
{
int max = arr[0];
//Ku k hum na 0 index wala ko sab sa bara samja is liya loop 1 sa sharu kara ga
for(int i = 1; i<n ; i++)
{
    //Ab hum kha ga k agr hamra jo 0 k bad wala index max yani jo abhi 0 per ha us sa bara ha to max pher i hi ho ga
    if(arr[i] > max)
    {
 max = arr[i];
    }
}
return max;
}
/*Ab hum ik or function banaya ga jo asal ma counting sort ka ik specilized verion ho ga ya ya kam kara ga k in ko count kara ga mtlb
bucket ma dala ga or unha pher sort ho ga us lahaz sa  
Is ma n size ha or exp ya wo exponational wala ha jasa 1 10 100 wala k kitna digits ko dakhna ha*/
void countingSort(int arr[],int n , int exp)
{
    /*Ab hum ik varibel banaya ga ya kam kia kara ga wo batata hu jasa k hum na dakha ha k agr 3 digit wala ha jasa 879 to 100 wala kam kara ga or
    ya 3 bar kara ga phala 1 k sath pher 10 k sath pher 100 k sath phala jab hum 1 k sath jo banaya ga usa is ma dal ga da pher is sa original array
    ma copy kar da ga isi tara jab 10 wala aya ga to pher wo is ma dala ga or udr sa yani output wala sa riginal array ma pher ya cpy ho 
    jaya ga isi tara 100 wala k liya bhi*/
    int output[n];
    //Ya nicha wala ik khali array banata ha jasa countsort ma banaya tha jis ma sab 0 0 fill kar dia ha or ya 10 daba ha ku k hum 0-9 tak hi rakhta
    int count[10]={0};
    /*Ab hum ik loop banaya ga jo original array k digit ko dakh kar us ka exp nikala ga or usa hamara array ma count aray ma us k index per
    0 sa ik ++ kar da ga jasa count sort ma kia tha is ki calculation asi ha
    jasa agr hamara pas ik array ha [170 4 890 . . . ] to ab sab sa phala digit ha 170 to (170/1)%10 yani 170%10 = 0 yani 0 index per*/
    for(int i = 0 ; i < n ; i++)
    {
        count[(arr[i]/exp)%10]++;
    }
    /*Ab hum ik or loop lagaya ga ya loop jo ha ya un number yani jo cunt kia ha usa aga bharhaya ga ya asal ma us count array ma sa akhri ki 
    position bataya ga ya kam kasa karta ha ya akhri index ki ginti jo countsort ma hoti ha us ma next ki ginti ko add kar data ha or udr likh data 
    ha jasa gar [0 2 0 0 0 0 4 0] ha na to ku k ya count[i] yani 1 sa ha count[1]+= count[1-1] ha na to is liya count[1]+=count[0] is tara ho ga
    ku k index 1 per 2 ha yani 2 bar count ha or count[0] ha to is liya count[1] =2+0 = 2 bana ga yani [0, 2, 0, 0, 0, 0, 4, 0, 0, 0] (Koi 
    change nahi hua, kyunke count[0] pher count[2] += count[1] ho ga yani count[2] = 0 + 2 = 2 bana ga count array ab: [0, 2, 2, 0, 0, 0, 4, 0, 0, 0]
    or asa hi aga continue hota raha ga
     */
    for(int i = 1 ; i<10 ; i++)
    {
        count[i]+= count[i-1];
    }
}
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
     {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);
    printArray(arr, n);
    return 0;
}