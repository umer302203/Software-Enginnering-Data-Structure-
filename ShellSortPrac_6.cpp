#include <iostream>
using namespace std;
/*Jo SHELL SORT ha wo asal ma INSERTION SORT ki hi ik upgrade ha bas insertion sort ma ya hota ha k hum ik ik kar k sab a compare kar k end ma swap
kar data ha lakn is ma bas thora sa change ha is ma hum divide karta ha or ik gap pada karta ha jaa 8 ha to 8/2 = 4 mtlb 4 k gap or pher 4/2 =2 mtlb
2 k gap or 2/2 =1 mtlb 1 ka gap yani 2/2 =1 per ya wohi insertion sort wala a jata ha


Hum ik simple sa print function bana lata ha tak bad ma bar bar print na karna para 
is ma hum na 2 input di k array kia ho ga or number kitna ha array ma yani 8 wala ha ya 7 wala ha ya jo bhi ha*/


void print_Array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
/*Ab hum ik function banya ga jo shell sort wala ho ga yahi wo kam kara ga is ma hum array or n input la ga ku k uper wala ma bhi hum na yahi kam kia ha
to is ma bhi yahi kam kara ga*/
void shell_sort(int arr[],int n)
{
    /*AB hum na jasa phala dakha ha hum is ma gap banata ha gap wise hum compare kar k swap karta ha t mtlb ya start hi gap sa kara ga 
    yani k agr 8 ha na total array ma elemnt to ya 8/2 kara ga or jasa k 8 hamara array ka total size yani n ha to hum n/2 kara ga wasa hum gap-- 
    bhi kar sakta tha ku k ya 4 2 1 is tara picha hi aya ga lakn /=2 zaida bhtr ha or gap++ t bilkul bhi nhi kar sakta ku k gap++ aga ki tarf la jata
    jasa agr phala 8 ko tora 4 ma to pher 4 ko 2 ma hona chiya tha na lakn ya 4 sa aga ki tarf 5 6 is tara chalta rahta or loop hamesha hi chalta 
    rahta is lya hum asa for loop lagaya ga*/
for( int gap = n/2 ; gap > 0 ; gap /= 2)
{
    /*Acha ab hum na ik loop to bana lia ha jo gap banata ha ya uper wala loop n/2 a gap banaya ga lakn hum inha swap bhi to karna ha na ik ki jaga dusra
    ko la ana ha or us dusra ki jaga per phala wala ko to huma in array ma j elemnt ho ga jo gap wala ho ga to unha select to karna ho ga huma 
    
    
    
    AB is lop ko dakho is ma hum na wo selector ko gap k brabar rakha wo is liya ku k gap jaha sa sharu ho ga wohi to elemnt hamara phala elemnt ho
    ga ya wohi element ha hamara jisa hum na select karna ha is liya hum na selector banaya ha or usa gap k brabar rakha ha or jab n tak jaya ga to khud
    hi loop khtm ho jaya ga ku k n number of arrays ha*/
    for(int selector = gap ;  selector < n ; selector++ )
    {
        /*Ab ya to thk ha lakn hu na jo select kia ha usa kisi jaga save karna ha to us k liya hum temp wala bananya ga jis ma ya save ho jasa hum 
        pala swap karta tha wasa hi ha */
        int temp = arr[selector];
        int searcher;
        /*Acha ab hum na ik loop bnaya ga ya loop hamara number k liya shi jaga dhonda ga hum isa searcher ka nam da data ha apni asani k liya
        
        Ab hum isa kha ga k selector ha jo gap ma sa elemnts ko select karta ha ya searcher k barabr ho ga wo is liya ku k hum na isi selector k liya 
        searcher ki madad sa shi jaga dhoundni ha pher hum kha ga k searcher jo ha wo gap k ya to barbar ha ya wo gap sa bara ha wo is lya ku k jab 
        gap wala index 2 per ho ga to us k mlb k selector bhi usi jaga h ga us na usi elemnt ko select kia hova ha to agr wo us jaga ha to mtlb searcher
        bhi usi jaga per ha  mtlb 2 > = 2 pher hum na AND condition lagai k arr[searcher-gap]>temp yani array ma searcher jo ha yani 2 wo - ho jaya gap jo 2 ha us sa
        or ya dono  temp sa bara ho yani arr[2-2]>temp -->  arr[0]>temp yani is k mtlb ha k index 0 tak kia temp sa bara ha    Agr in ma sa koi ik conition
        bhi false hva to loop nhi chala ga or wasa  ya  searcher >= gap hamara saftey check tha taka ya negative(-) ma na jaya ku k agr negtive ma jaya ga
        to pher ya error da ga or program crash pher hum na isa kha k jo seacher ha na wo -= gap ho mtlb  jis gap sa aga gaya ho usi gap sa picha awo
        mtlb jasa agr 2 ka gap sa aga gaya to 2 k gap sa hi picha awo */

        for(searcher = selector; searcher >= gap && arr[searcher - gap]> temp; searcher -= gap )
        {

            /*Ab hum na jo searcher -gap kia ha us k jo inde ho ga mtlb in dono ko minuse kar k wo arr[searcher]  ma ave kar da ga is k bad loop jab khtm ho jaya ga
            to us k bad aga jo hum na temp ma value save ki thi usa searcher ma wapas ave kar da ga*/
            arr[searcher] = arr[searcher - gap];
        }
        /*Ya hamara loop k bhair wala ha ya temp ki value save kara ga searcher ma jo index ho ga agr index is ma 4 ha to temp ki value 4 per save kara ga*/
        arr[searcher] = temp;

    }
}
}

/*Ab hum main wala functn ma isa use kara ga */
int main()
{
    int arr[] = {12, 34, 54, 2, 3};

    /*Ya hum na nicha wala is is waja sa kia ha ku k is sa huma ttal number of array lka pata lag jata ha is sa ya ho ga k ku k huma ya pata ha k
    phala inde 0 hi hota YA SIZEOF WALA C++ KA HA YA HAR ARRAY MA JITNA NUMBER HOTA HA UN MA HAR IK KA TOTAL SIZE BATATA HA JASA IS MA 12 KA INT HA
    NA TO IS LIYA IS K SIZE 4 BYTES HO GA OR IS TARA PORA ARRAY K HAR NUMBER KA SIZE MALOOM KARA GA
    jasa k sizeof(arr) ya bata ha k pora array kitni jaga memory ma laata ha jasa ya 5 number ha or har number 4 bytes ka ha to 5x4 =20 ha or jo 
    sizeof(arr[0]) ha is k mtlb ha k phala wala k size yani 4 bytes     To us k bad hum na divide kar dia    sizeof(arr) / sizeof(arr[0])      yani
    20/4 = 5 yani is k mtlb n =5 ka ha ku k huma to nazar a raha ha k 5 ha lakn computer ko nhi pata hta w nhi dakh sakta hum jasa */
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before Sorting: ";
    print_Array(arr, n); 

    shell_sort(arr, n);

    cout << "Array after Sorting:  ";
    print_Array(arr, n);

    return 0;
}
