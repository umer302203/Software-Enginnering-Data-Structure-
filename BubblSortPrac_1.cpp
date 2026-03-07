#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n = 8;
    int arr[n] = {9, 1, 7, 8, 5, 2, 6, 3};

    // Ya wala jo loop ha ya is nicha wala pora process ko repeat karta ha n-1 bar wasa hum n bhi likh sakta tha ku k pher ya 8 bar repeat karta lakn
    // hamara 7ve per hi ya kam ho jata ha
    for (int outerloop = 0; outerloop < n - 1; outerloop++)
    {
        // Ab hum ik loop banaya ga jo har element ko swap kara with condition k
        // Is loop ma hum na 0 sa sharu kia ku k index 0 sa hi sharu hota ha
        /*Is ma hum na n-1 is liya kia ku k agr hum kahli n likh data to pher
        ya 8+1 bar karta jo k out of bound tha or error data ha   */

        for (int innerloop = 0; innerloop < n - 1; innerloop++)
        {
            // Hum na condition lagai ku k huma asa chiya tha k agr phala wala arry apna sa agla wala array sa bara ha tab swap karna
            if (arr[innerloop] > arr[innerloop + 1])
            {
                // SWAP:
                // Hum na temp banaya ku k is ma hum apna phal elemnet rakha ga
                int temp = arr[innerloop];
                // Pher ab ku k phala wala khali ho gia ha to us ki jaga ab hum 2ra wala rakha ga
                arr[innerloop] = arr[innerloop + 1];
                // Ku k ab dusra wala khali ha or temp ma hamara phala wala varibel store ha to us ma hum phala wala dobara rakh la ha
                arr[innerloop + 1] = temp;
            }
        }
    }
    //Ab hum ik or loop lagaya ga jo k is array ko sort kar k dikahay ga mtlb simple ma khu to print kara ga
    for(int print_sort = 0;print_sort<n;print_sort++)
    {
        cout<<arr[print_sort]<<" ";
    }
}