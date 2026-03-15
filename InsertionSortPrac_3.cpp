#include <iostream>
using namespace std;
int main()
{
    int n = 8;
int arr[n] ={8,7,6,5,4,3,2,1};
/*Ab ku k insertion sort ma hum phala wala elemnt jo index 0 per para hota ha usa sorted samj lata ha baki 
unsorted hta ha asa [sorted(0) unsorted(baki sara unsorted)] to is liya hum 0 inde sa to sharu kar nhi sakta 
hum 1 sa sharu karu ga*/
for(int unsorted = 1;unsorted <n;unsorted++)
{
 /*Ab ku k hum na yaha takk kar lia ha ab jasa k huma pata ha k index 1 per jo element hota ha usa "Key"khata ha
 yani jo hamara loop sharu hova ha wo unsorted = 1 sa hova ha index 0 sa nhi hova to simple mtlb hamara int key jo
 ho ga wo unsorted hi ho ga*/
 // ...............YAD RAHA K HUM INDE KI BAT KAR RAHA JO ARRAY YANI arr MA HOTA HA...............
 int key = arr[unsorted];
 /*Ab hum apna phala point jis k hum nam da ga sorted banaya ga wo index 0 ha yani unsorted-1*/
 int sorted = unsorted-1;
 //...................................................................................
 /*Ab hum na khuch asa karna ha k jo hamara sorted elemnt ha usa su ki shi jaga per la jana us k lya hum while
 loop lagaya ga ku k while k mtlb ha jab tak mtlb jab tak condition true raha gi code execute hota raha */
 //.................AB WO CONDITION...................
 /*Ab hum while loop lagaya ga jasa k phala bataya ha is ma hum na ik condition lagai k jo hamara sorted yani
 phala index 0 wala elemnt ha na wo 0 k barabar ya 0 sa bara ho ya is liya kia ku k jab hum  na unsorted yani index
 1 wala ko -1 kia yani unsorted-1 to pher agr unsorted 0-1 hota to -1 ho jata jo k error da data ha
 or sath ma hum is k  sath and ma ik or condition lagaya ga k kia sorted hisa jo left side wala ha kia us k wo
 sorted hisa key sa bara ha ku k hum na yahi to karna ha k hamari key jo ha jo unsorted hisa ka phala elemnt 
 ho ga jo waqat k sath sath kam hota jaya ga wo kia sorted element sa chota ha */
 //AB HUM NA 2 KAM KIA IK YA K AGR SORTED 0 SA AGR BARA HO YANI PORA SORTED ARRAY KI BAT NHI KAR RAHA
//AND SORTED YANI US K INDEX AGR HAR INDEX AGR KEY SA BARA HA YA DONO AGR CONDITION TRUE HO GI TAB AGA
 while(sorted >=0 && arr[sorted]>key )
 {
    /*Ab jab k conition true ho to ya line chala gi ya line asal ma shifting ya pushing ya asa samjho k jaga bana
    rahi ha
    AB ya line khuch asa kara gi k jo hamari key ha us k liya jaga banaya gi wo jaga kasa banaya gi wo dakhta ha
    Ya ya kara gi k jab conition tru ho gi yani k arr[sorted] bari ho gi key sa to pher jo sorted element ho ga
    wo ik kadam aga aya ga mtlb wo exact sorted ki jaga a kar replace ya overwirte nhi kara ga balka wo ik kadadm
    aga bhara ga or aga insert kar da ga jasa agr 5 ha t wo 4 r 6 k darmain 5 ko dal da ga */
    arr[sorted+1]=arr[sorted];
/*Ab hum ya bhi dakhna ha k pichal elemnt ko bhi key sa compare to karna ha to hum ya line likhata ha yani k 
huma har pichal left wali side sa key sa compare karna parta ha ya dakhna k liya k kia ya key choti ha in sab sa
agr key kisi ik sa bari ho to us k aga hum us key ko insert kar data ha*/
sorted = sorted-1;
 }
 /*Jasa k phala bataya ha ma na k agr key choti na ho to usa apna sa chta elemnt k aga dal dia jata ha
 Ya bhi yahi code ha k agr while loop wali conition false ho jaya gi mtlb k ab ya elemnt sorted element key sa
 chota ha is liya hum kha ga k ab apna us sorted index sa ik qadam aga insert kar do */
 arr[sorted+1]=key;
}
/*Ya wohi k ab us array ma sa i ki madad sa har elemnt ko pick karo or show kar d*/
cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

}