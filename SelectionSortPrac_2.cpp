#include <iostream>
using namespace std;
int main()
{
    int n = 8;
    int arr[n] = {8, 1, 4, 2, 7, 5, 3, 9};
    // Ab phala hum ik loop lagaya ga jo 0 index sa la kar 7 tak(8) tak jaya
    // Ya har position k liya chala ga
    for (int outerloop = 0; outerloop < n; outerloop++)
    {
        /*Ab ku k jo hamara outer loop ha wo sab ko scan kara ga mtlb agr wo 8 per
        ha to is k mtlb hamara min_index bhi 8 per hona chiya sharu ma
        Us ki waja ya ha k filhal to hum phala inde jis a outer loop sharu kar raha ha
        usi hi sab sa chota samja ga is liya hum na min_inde ko kha k ya bhi outerloop k barabar ha
        yni abhi wo 8 ha  */
        int min_index = outerloop;
        /*Ab hum ik loop banaya ga jis ka nam ha outer loop jo outer lop sa ik number aga sharu ho ga yani
        outerloop+1 or n tak jaya ga n sa chota ho ga .Ya hum na is liya kia ku k hum na min_index
         ko outerloop k barabr rakha or hamrsha ya innerloop outerloop
        sa ik elemnt aga ho ga */
        for (int innerloop = outerloop + 1; innerloop < n; innerloop++)
        {
            /*Ab huma ku k ya zaort ha k asa elemnt dhnda jo min_index sa chota ha to us k liya
            pher hum condtion lagata ha k kia outerloop na koi asa elemnt dhonda jo min_index sa chota ha
            YAD RHA:hum is ko ult nhi kar sakta hum ya nhi kha sakta k kia min_index ko koi chota elemnt mila or innerloop sa compare kara ya ghalt
            ho ga ku k asal ma innerloop hi elemnt ko dhond kar min_index sa compare kar raha ha */
            if (arr[innerloop] < arr[min_index])
            {
                // Agr cndtion true hoi to hum  min_index ma innerloop wala us elemnt ki inde rakh da ga
                min_index = innerloop;
            }
        }
        /*Hum swap ka function outer loop ma rakha ga us ki waja ya ha ku k agr hum inner loop ma rakha to pher wo compare karta sath hi usa swap kar data
        lakn hum ya chata ha k ya phala compare kara sab ko or end ma ik bar ma hi swap kar da */
        int temp = arr[outerloop];
        arr[outerloop] = arr[min_index];
        arr[min_index] = temp;
    }
    // Ab hum print karwa da ga us sorted array ko scren per
    // Yad raha hum print_sort is liya use kia ku k ya us arr ma sa ja kar ik ik element uthaya ga r
    // print kara ga
    for (int print_sort = 0; print_sort < n; print_sort++)
{
    cout << arr[print_sort] << " ";
}
return 0;
}


