#include <iostream>
using namespace std;

/*Ya wohi phala wala ha jo hum arrays k scren per dikhana k liya use karta ha ya wo ha */
void printArray(int arr[], int n)
 {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
/*Ab ku k hmara count sort ha t us k liya hamara logic ya ha k hum ik array banat ha jo khali hota ha us ma bas inde number hota ha phala hum check
karta ha k hamara kon sa pora array ma sa number bara ha pher us lahaz a hum unta ka dura array banata ha jasa agr ik ma ha 7 maximum to hum max+1 yani
8 banata ha or isi tara hum check karta ha k main sort ma kon a number kitni bar aya ha agr 1 jo ha wo 2 bar aya ha to index 1 per 2 ho jaya ga isi 
tara agr 4 3 bar aya ha to index 4 per 3 ho jaya ga pher hum dobara inha final sorted karta ha  jis ma hum yu karta ha k sab ko alag alag karta ha
mtlb is k ya ha k agr jasa 1 jo ha wo 2 bar aya ha to usa alag alag kar lata ha jasa 1 1 is tara aga 4 jo ha wo 3 bar aya ha to us lahaz sa 4 wo 3 bar
likha jaya ga asa 4 4 4 t is tara final sorted ho ga */


/*To ab usi k liya hum ik function banaya ga jis k nam rakha ga counting_Sort
Jasa k hum na ik void funtin banaya ga jo array or n yani us k size input la ga*/

void counting_Sort(int arr[], int n)
{
/*Ab hum na jasa k phala dicuss kia hum phala pora array ko scan kar k sab sa bara elemnt ko dhonda ga w is loya taka us jitan bara arry bana saga 
agr hum 8 k array bana da r bara number ho 20 to pher error hi aya ga na or dusra 20 inde per 20 k kasa save kara ga jab 20 index hi nhi ho ga bas 8 tak
ho ga is liya huma ik maimum number wala ik varibel banaya ga jo save kara usa*

Ab huma nhi pata k kon sa elemnt bara ha lakn or na hi hum asa koi kar akta ha ku k cmputer ko ya nhi ata hta k kis inde per kia hta ha hum apni 
ankho a to dakh sakta ha lakn computer nhi computer ko bas ya pata ha k arr[0] hota ha usa ya bhi nhi pata k akhri elemnt kon sa ha ku k kia pata hum
total 10 kar da ya 100 element agr hum index[8] karta to baki jo 2 ya 92 ha wo kha jata huma ya to pata ha k sharu to ya 0 sa hi hota ha is liya hum
farz kara ga k hamara sab sa bara number index 0 per ha */

int max = arr[0];
/*Ab ku k hum na farz kar lia ha k ya 0 per ha lakn ya bas ik farz ha asal ma asa ho sakta ha ya nhi ya huma nhi pata to us k liya hum  ik loop chala 
kar conidtion da ga 
Wo asa ha hum ya ik maximum_finder jo ha wo la ga us sa pora array ko scan kara ga or dakha ga k kon sa bara ha
Hum ya loop 1 sa sharu kara ga ku k hum already index 0 wala ko kha chuka ha k ya sab sa bara ha or pher baki n tak jaya ga or ++ hota jaya ga ab ya
sab ko check kara ga */
for(int maximum_finder = 1 ; maximum_finder < n ; maximum_finder++)
{
    /*Lakn hum na maximum_finder ko use to kar lia ya scan karta raha ga lakn isa kasa pata chala ga k kon sa bara ha 
    Is k liya hum ik conition lagaya ga Hum isa kha ga k agr maximum_finder na jo varibel per apna hath rakha ha ya max us arr[0] ma para elemnt sa bara 
    ha (Ya wohi arr[0] ha jisa hum na sab sa bara farz kia tha) to wo max ko upade kar da us ma wo wala save kar da
    Ab ya phala check kara ga ya dakha ga acha 1 sa bara 2 ha ya usa max ma save kar da pher ya kha ga acha to 4 2 sa bhi bara ha t ya 4 ko ave kara ga
    isi tara ya loop chlat raha ga jab tak conditon false nhi ho jati*/
    if(maximum_finder> arr[0])
    {
        /*Or jasa k bataya k ya is max ma ya maimum_finder usa save karta raha ga jab tak bara na mil jaya*/
        max = arr[maximum_finder];
    }
}
/*Ab hum na maximum number ko ave karna wali jaga to bana li ha lakn is maximum number jitna bara number rakhna k liya utni hi jaga to banani para gi
mtlb ap ko pata h k class ma 20 students ha to ap 20 student k liya hi seats lagaoo ga ku k ab ap ko ya pata ha k maimum 20 student ha

To us k liya hum ik array banaya ga jis ma utni jaga honi chiya mtlb maximum number ha 7 to max wala ma 7 store ho ga lakn huma pata ha k 7 agr bara ha
to index 0 sa sharu ho ga to us k liya hum +1 karta ha ku k agr hum kha ga k max=7 k liya jaga banao to mtlb 8 nhi balka 7 hi jaga banao jo ghalt ha 
ku k hum 0-7 tak jata ha jo 8 hi ha*/
int count_new_array[max+1];
/*Ab hum na jaga to set kar di k kitni ho gi lakn jasa k count sort ma hum jo new array banata ha wo khali hota ha khali k mtlb ha k waha 0 hota ha
sab ma to ab hum ik naya for loop laga kar is ko 0 sa bhar da ga*/
for(int array_filler = 0; array_filler <= max;array_filler++)
{
   /*Ab hum na jo count_new_array wali jaga banai us ma hum 0 fill kar da ga or wo 0 kon fill kara ga wo jo hamara array_filler ha  ku k is ma hum na
   uper wali line ma isa ya condition di ha k max k barbar ruk jana is sa bara na hona yani max agr 7 ha to is k 0 sa 7 tak fill kar dana
   YAD RAHA k hum ya 0 sa sharu karta ha inde bhi or ya loop bhi tab hi hum na max tak kia  */
    count_new_array[array_filler] = 0;

}
/*Ku k hum na ya khali 0 sa bhara array bana lia ha ab hum chata ha k original array ma jo number ha us ko us k index per rukh dia jaya
Yani is k mtlb ya ha k agr hamara pas 1 jo ha ya 2 bar aya ha to index 1 2 bar bhar jaya ga jasa 
                         [0 2 0 0 0 0 0 0]
                 index-->[0 1 2 3 4 5 6 7]
Ab dakha jo number jitni bar aya ga utni bar us k inde ma 1 plus ho jaya ga*/


/*Ab is ma dakho hum ik naya varibel banaya ga jo original array ma sa elemnts ko pick kara 0 sa sharu ho ga or bhata jaya ga n sa phala tak*/

for(int array_picker = 0 ; array_picker > n; array_picker++)
{
    /*Yaha asa ha k hum original array yani arr ma sa array_picker ki madad sa number ko uthaya ga yani arr[array_picker] yad raha k index level per
    ya kam karta ha jab hum [] ya use karta ha or usa count_new_array ma us ki asli jaga per 0 ko overwrite kar da ga yani i k mtlb ya ha k agr 
    for example ya phala pora original array ko dakha ga agr waha per index 0 per agr ha 1 to pher wo count_new_array ma kar usi array yani 1 per 
    yad raha idr hum 0 per nhi jaya ga ku k udr sa hum na jo index pick kara ga us per jo bhi number ho ga jasa agr index 3 per number ha 7 to 7 index per
    ik increase kar da ga agr 0 ha t 0 sa 1 increase ho jaya ga is liya hum na count_new_array[]++ kia ha*/
    count_new_array[arr[array_picker]]++;
}
/*Abhi tak hum na array ko ++ kar lia ha index k lahaz sa ab un ko utna hi martaba lijhna ha jasa index 0 per 0 ha to usa skip kar dana ha pher
 index 1 per 2 ha mtlb 2 bar 1 1 aya ha t hum 2 bar 1 1 likha ga is tara baki sab  kara ga 
 To is ka logic bana ha ab hum na sab sa phala ik writer variable banaya ga ya varible jo ho ga ya ya kam kara ga k jo hum arrays ko sort kara ga 
 ya un ko likha ga mtlb jasa 2 1 ha to ya in ko sort kara ga
 Yad raha hum yaha jo bhi writer varibel sa likha ga wo originzal array yani arr ma likha ga hum ik tesra array bhi bana sakta tha lakn hum na isi ma
 yani original array ma ya kara ga ku k is sa memory bachti ha
 To hum writer ko 0 k barbra karta ha ku k ya index 0 sa chalta ha*/
 int writer = 0;
 /*Ab hum ik loop lagaya ga jo array ko us k index k lahz sa dakha ga mtlb aal number ko dakha ga simple kar k bataoo to ya us array k jis 
 index per ho ga usa hi asal number mana ga to us k liya ya max tak chala ga */
 for(int original_num = 0 ; original_num <= max ; original_num++)
 {
    /*Ya uper wala loop jasa k pata ha k original number ka pata da ga lakn hum na to us k index k lahz sa us number ko alag bhi karna ha yani is k
    mtlb ya ha k agr index 2 per 4 ha to huma ya pata ha k 2 index 2 ha asal number 2  or is per 4 ha mtlb 4 bar 2 aya ga pher huma inha tarteb sa 
    2 ko 4 bar likhna para ga jasa 2 2 2 2 asa to ya ya giniti in ki kha per hum na rakhi ha yad ha wo hum na count_new_array ma rakhi ha 
    
    Ya dakho ya ab spilter jo  ha jo is k kam ha k jo jis index per jo number ha us index ko utni bar split kar dana ha jasa agr index 3 per 2 ha to
    3 ko 2 bar likh da yani 3 3. To ab is la logic samjta ha ya spilter 0 sa sharu ho ga or pher hamara wo new array jis ma hum na ginti save ki hi thi
    us ma jo hum na original_num wala varibe banaya ha us tak jaya ga or ++ hota jaya ga yani is k mtlb ya ha k jasa uper wala loop chala ga 
    To for example ya orignal_num ha 1 index per yani ya original number 1 hi ha to ya nicha wala loop check kara ga k 1 per kitna count ha yani 2 ha 4
     ha ya kia ha pher utni bar wo chala ga agr 1 per 3 ha to ya 3 bar chala ga*/
    for(int spilter = 0 ; spilter < count_new_array[original_num]; spilter++)
    {
        /*Ab jab ya 3 bar ya jitni bar bhi chala ga to hamara orignal array ma jo writer ho ga mtlb filahl wirter ki position 0 per to us per jo 
        original_num ho ga usa likh da ga yani agr original_num ma ata ha k abhi 1 ha to ya writer index 0 per 1 likh da ga agr pher count_new_array khata ha
        k ab original_num per 1 ha to pher writer ik step aga bhar kar 1 dobara likh da ga is liya hum na writer++ kia ha*/
        arr[writer] = original_num;
        writer++;
    }
 }



}



/*Ya wala main ka hisa ha jasa phala ki bar dicuss kia ha */

int main() 
{
    int arr[] = {1, 4, 1, 2, 7, 5, 2};
    //Ya wohi size bata ha ik array ma ik elemnt ka size 4 bytes hota ha us lahaz a amj jawo jasa phala discuss kia tha
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    counting_Sort(arr, n);

    cout << "Sorted Array:   ";
    printArray(arr, n);

    return 0;
}
