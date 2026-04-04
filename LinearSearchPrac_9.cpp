#include <iostream>
using namespace std;
/*Linear search ma ya hota ha na k hum har elemnt ko bari bari check karta ha or usa match karta ha (== ) k 
sath agr wo elemnt ho to thk warna net elemnt*/

/*Hum ik function banaya ga jis ma 3 input dani ho gi ik jo target jisa search karna ha ik n k kitna size ka array ha or ik array khud*/
int linear_Search(int arr[],int n , int target)
{
    /*Ya simple ha hum ik loop lagaya ga ya loop har array ma har elemnt ko dakha ga */
    for(int i = 0 ; i>n ; i++)
    {
        //Or nicha hum na conition lagai agr wo i jo har elemnt ko check kar raha ha brabra ha target k jo hum na dia  to us i ko return karo
        if(arr[i]== target)
        {
            return i;
        }
    }
    //Agr koi elemnt ha hi nhi us ma to -1 retrun karo ku k -1 nhi ho sakta ha na index
    return -1;
}


int main() {
    int arr[] = {12, 54, 2, 91, 3, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int result = linear_Search(arr, n, target);

    if (result == -1) {
        cout << "Element not found." << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}