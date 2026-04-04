#include <iostream>
using namespace std;
/*Acha ab hum ik function banya ga jo int return kara ga ku k huma ik number return karna ha agr hum void karta to ya khuch bhi return na karta or
us k koi faida bhi nhi hota to is waja sa hum na ya kia or dusra
Hum is ma array ko input la ga jasa phala lia or merge sort kia tara is am bhi midle left or right wala ho ga ku k ya search ha
Yad raha ya jo binary search ha ya bas sorted array per kam karta ha or logic bhi yahi ha na
Acha jasa hum na merge sort ma kia tha k wo middle ko dakhta ha ya searching hi middle sa karta ha ya middle wala hamri boundry ha thk ha na to
us k bad jab ya middle wala kara ga to us elemnt ko check kara ga jia search karna ho ga for eample wo left side per ho ga to ya right wala ko discard
kar da ga or same yahi process left wala per apply karta raha ga is liya hum while loop lagaya ga*/

int Binary_Search(int arr[], int left, int right, int target)
{
    /*Ab dakho hum na while loop lagaya ha hum kha ga k agr left wala right sa chta ha or ya logic ha ku k elemnts jo ha wo sorted ho ga or chota sa
    bara i tarf yani 1 2 3 4 5..... is tara ho ga is liya ya conition ha mtlb ya loop tab chala ga agr wo number right wala sa chota ho ga ya us k
    brabar jasa 0 bara ha 9 sa */
    while (left <= right)
    {
        /*Ab hum mid calculate kara ga ku k hum na loop ki conidtion to da di ha*/
        int mid = left + (right - left) / 2;
        /*Ab hum conition lagya ga if k sath jasa k hum pata ha k agr mid brabra ha target k yani hum na shi donda
        agr nhi to wo ya to left ma ha ya right ma*/
        if (arr[mid] == target)
        {
            return mid;
        }
        /*Agr mid wala chota ha target sa mtlb left = mid+1 to ya ik qadam aga chala ga  mtlb hum left hisa ko discard kar da ga agr midle wala elemnt target
        sa chota ha  mtlb hum right ki tarf jana ha is liya left ko discard*/
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        /*Acha ab is ma asa ha k jab wo middle elment right wala sa bara ho ga yani left wala sa chota nhi ho ga to pher is k mtlb isa left wali side
        per ana chiya <-------- is tarf */
        {
            right = mid - 1;
        }
        /*Ab hum retrun -1 kara ga ku k index khabhi -1 nhi hota or return -1 is liya agr wo elemnt ha hi nhi fail safe wala tarika*/
    }
    return -1;
}
int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    // Size(Bytes) k lahaz sa n find karna wala tarika
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = Binary_Search(arr, 0, n - 1, target);
    // Ya wohi k jo hum na result wala banaya ha us k liya  jaa phala bataya agr -1 aya to mtlb mojood nhi
    if (result == -1)
    {
        cout << "Element is not present in array" << endl;
    }
    else
    {
        cout << "Element is present at index " << result << endl;
    }

    return 0;
}