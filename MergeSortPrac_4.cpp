#include <iostream>
using namespace std;
// AB HUM IK FUNCTION BANAYA GA JO ARRAY K HISO PER KAM KARA GA YA PORA ARRAY PER KAM NHI KARTA YA ARRAY K HISO PER KAM KARTA HA JASA LEFT OR RIGHT ARRAY
//_______________________________________________________________________________________________________________________________________________
/*Acha ab is function ma hum 3 parameter la ga ik left wala ik right wala or ik midle wala bhala asa ku kara ga wo is liya ku k hum na
apna array ko jab split karna ha (Asal ma ya aray k anadr hi h raha hota ha array ko hum split nhi karta) to huma ya pata hona chiya k left kha khtm
hota ha or right kha sa sharu hota ha to us k liya hum ik midle ka bhi varibel banay ga jisa tum borderline kha sakta ho */
void merge(int arr[], int Left, int Middle, int Right)
{
    /*Ab ku k jasa huma pata ha k jab hum inha sort kar raha ho ga to us waqat hum inha replace kara ga mtlb jasa agr ya ha  [3 5 6 7 ] to is ma agr
     3 ki jaga 6 ko rakhna ha or 6 ki jaga 3 ko to is sa ho ga ya k 2 ki jaga to hum 6 rakh la ga is sa 3 ki jaga 6 a jaya ga r us a hamara 3 replace ho
     jaya ga 6 sa jis a h ga ya k jab hum 6 ki jaga 3 rakkhna chiya ga to wo to ho ga hi nhi ku k us ki jaga 6 a gia mtlb 6 ki jaga 6 hi aya ga to
     us masla ko hal karna k liya hum ik backup banta ha taka pher hum original arry ma swaping kar saga hamara pas apna ik backup ho ga*/
    //.............................................................AB CONDITION DAKHO...........................................................
    /*Ab hum phala ya ta kara ga k is ma middle kon sa ha or left kon sa ha or right to is k liya abhi is jaga hum middle ko define nhi kara ga waa pher
    bhi bata data  hu k middile nikalana ka formula ya ha [Middle = Left + (Right -Left)/2]  lakn ya agla jo dusra function banaa ha us ma kara ga
    Ab dakho for example mara pas middle ha 3 mtlb agr 8 number ha to us ma 0-7 index banta ha to us ma sa middle nikalta ha 3
    Ab dakhna k is logic ma hum na left wala hisa ko alag karna ha or right wala ko alag ku k hum na arrrays ko torna ha agr 4 ha to 2 2 hiso ma agr 2 ha
    to 1 1 hisa ma to us ma conition ya ha
    jasa k ma na phala bataya ha k middle 3 ha to us lahaz sa 3-0+1 ab tum soch raha h ga k ya 0 kha sa a gia ha or +1 ku kia to ma batata hu
    wo is liya ku k agr 8 ha total elemnt to is k mtlb 4 4 2 hisa ho ga asa ha na to us lahz sa bhi hum asa kara ga k hamara middle 3 ha or left wala 0 ha
    to 3-0 kitna hota ha ya 3 hi hta ha agr asa hi kara to ya to 8 ma sa hamara 3 hisa ik jaga ban jana ha or 4 ik side jo n2 ma ha to baki 4tha elemnt
    kha gia is liya hum na asa kia
    n1 =3 - 0 +1 = 4*/
    int n1 = Middle - Left + 1;
    /*Ab same ya bhi ha ya n2 right wala k liya jaga bana k liya ha mtlb k mara khana k mtlb ya ha k ya batan k liya k right k index kha a sharu hona ha
    ab dakho 8 elemnt mtlb index 7 per end to is lahz a sab sa last wala 7 hi ha na to
    n2 = 7 -3 = 4
    dakho samj i n1 bhi 4 ha or n2 bhi 4 ha agr 9 array wala hota to pher 4 n1 hta or 5 n2 ho ga asa ha na ya bas us k logic ha k kasa btana ha k left
    wala hisa kon sa ha or right wala */
    int n2 = Right - Middle;
    /*AB hum na logic ya tarika to bana lia ha jaga banaa k liya k kis k hisa kitna ha or kis ka kitna lakn hum ab is hisa ko rakhna k liya jaga bhi to
    banaya ga hum compiler ko kha ga k in dono hisao k liya jaga banao to  is ma left_array or right_array ya jaga ha or wasa ya in dono side ki jaga ha*/
    int Left_Array[n1], Right_Array[n2];
    /*Ab hum na compiler ko ya bhi bata dia ha k jaga rakhna in dono k liya to is jaga ma is k hisa bhi rakhna ha to loop lagaya ga hum ik jaga fill karna wala
    ponter ko kha ga k karo or i tara k 2 loop banya ga taka wo fill kara ik ko kha k ga k n1 yani 4 sa bara ho na mtlb inde 3 ku k index 0 sa sharu hta ha
    is lahaz sa 4 hi banta ha  */
    for (int left_value_filler = 0; left_value_filler < n1; left_value_filler++)
    {
        /*Yha bhi whi k Left array ma wo value filler jaya or is left array wali jo jaga hum na compiler ko kha kar banai usa fill karta jaya ya asa ho ga
        k phala jab loop chala ga to ku k ya 0 sa sharu hota ha to left_value_filler 0 ha to mtlb k inde 0 per save karna ab kia karna wo = k bad batata ha
        wo khata ha k jo array ha us ma left+left_value_filler is k mtlb ya ha k ku k left 0 sa sharu hova ha to 0+0 yani 0 yani ya phli wali value store kar da ga wo is liya ku
        k jasa jasa wo left side wali yani  Left_Array[left_value_filler] is ma jo index ata jaya ga us ma value stre hoti jaya gi jasa agr inde 1 ab ha
        is per to arr[0+1] ku k huma pat ha k left wali phala index ha jo k 0 hi ha to is liya yahi raha ga or jasa k ab idr left_value index_filler ma value 1 hoi
        to idr bhi 1 hi ho jaya gi yani 0+1 =1 mtlb 1 per value store ho gi index 1 ki*/
        //..............................................................................................................................
        /*.................................................IMPORTANT NOTE...............................................................*/
        // ABHI k liya hum bas yahi samj  raha ha k ya sorted hisa ha ku k merge function sorted nhi karta wo asal ma mergesort yani dusra wala function
        //  sort karta ha to is liya ya abhi k liya asa samjo k sorted hova hova ha
        //___________________________________________________________________________________________________________________________________
        Left_Array[left_value_filler] = arr[Left + left_value_filler];
    }
    // Ab same yahi process right wali jo jaga hum na compiler ko kha kar bani us k liya ha
    for (int right_value_filler = 0; right_value_filler < n2; right_value_filler++)
    {
        /*Ab dakh is ma bhi wasa hi ku k huma ya to pata ha k right wala jo ho ga wo ab sa last wala ho ga is liya hum na ya condition di or middle ka
        formula hum na phala bhi agla function ma lagya ga ku k asal torna wala kam udr hi hona ha wohi function kara ga to is liya dakho agr middel 3 ha
        to 3+1+0 ku k ya right_value_filler 0 sa sharu ho ga  yani 4 mtlb Middle+1 hamra starting point ha ku k middle 3 tha to 3 sa aga bhara ga mtlb 4 samj agi*/
        Right_Array[right_value_filler] = arr[Middle + 1 + right_value_filler];
    }
    /*To ab hum na wo Left_Array or Right_Array wali jaga bana to li ha us ma value bhi copy kar li lakn hum inha read bhi to karna ha ku k ya hamara backup ha
    or huma is ki zarat bhi ha to us k liya hum ik pointer banaya ga sab k liya mtlb asa samjhao jasa har jaga k liya ik superviser banaya ga*/

    int reader_LA = 0; // Reader for Left_Array(LA)----->i bhi kha sakta
    int reader_RA = 0; // Reader for Right_Array(RA)----->j bhi kha sakta

    /*Dakho hum na 2 banya ha or ya dono yani left or right array wali jago dono k liya ha lakn hamara asal jaga jo arr ha us k liya bhi to hum chiya na jo us ko manage
    kar saga ya phar saga to us k liya bhi hum bana lata ha jis k nam rakhta ha k or isa hum Left k barbra rakha ga ab sawal ya ha k left k barabr ku rakha ga
    Left k brabr is liya rakha ga ku k har main jaga yani arr k starting point Left hi hota ha for example agr haara ik aray ma darmina ma sa jo tora hova ha
    to agr hum int k = Left nhi kara ga to ya ghalt  ho ga mtlb filahl sharu ma to Left 0 sa sharu hota ha lakn agr hum is
    a kha k int k = 0 to jab ya darmn ma sa sharu h ga merge
    sort to us waqat 0 to nhi h ga ho sakta ha us waqat 5 ho  or huma pta ha k phala elemnt Left hi hota ha to is liya*/

    int writer_main = Left; // Writer for Main array(arr)------->k bhi kha sakta

    /*Acha ab ya to ho gia ha lakn huma in Left or Right array ko combine yani merge bhi to karna ha to us k liya bhi hum ik asa loop chiya jo in Left_array or
    Right array ko merge karta jaya lakn masla ya ha k huma ya to pata ha k condition khtm kha honi ha lakn huma ya nhi pata k condition start kha honi ha
    or jab huma ya pata ho k cnition rukni kha ha to pher us  k liya hum while loop lagata ha
    AB hum na in Left or Right array yani Left_Array or Right_Array ko read karna ha to us k liya hum na uper wo reader bana lia ha to ya har reader us array k size tak jaya ga
    jo hum na n1 or n2 ki madad sa bataya tha k n1 kha tak ha array ma or n2 kha tak ha   (yani is k mtlb ya ha k jasa 8 k array ha to usa 2 hiso ma divide kara
    left or right to un k 4 4 k 2 hisa banta ha na ya wo bat kar raha ha or ya number k left ka kia hisa banta ha or right ka kia  hisa banta ha wo ya )
    */
    while (reader_LA < n1 && reader_RA < n2)
    {
        /*Hum ik condition lagaya ga k kis ma elent chota ho or kis na bara hu ku k left wala ma chota hona chiya or right wala ma bara to us lahaz sa hum conition lahagya ga or
        ya hamara reader jo ho ga ya huma bataya ga k left wala or right wala ka compareion kara ga k kon sa chta ha or kon sa bara agr chta hova t wo left wala k la ga or agr bara hva to right ka
        ku k wasa bhi hum na left ma chota or right ma bara elemnts rakhna ha */
        if (Left_Array[reader_LA] <= Right_Array[reader_RA])
        {
            /*Pher aga hum ya kha ga k hamara jo original array ha main wala(yani arr) us ma pher values rakhta jawo phala Left_Array ki rakha ga pher agr condition false hi to Right_Array ki*/
            arr[writer_main] = Left_Array[reader_LA++];
            /*Ab ap ya dakha k ya left_array wala k elemnt main ma dal raha ha lakn yaha ik important bat ku k hum na reader_LA++ kia ha to phala index yani
            0 wala phala store ho ga pher us sa aga ku k reader_LA sharu ma to 0 per hi tha na pher bad ma ++ hova or yahi same bat duri line ma reader_RA k liya ha*/
        }
        else
        {
            arr[writer_main] = Right_Array[reader_RA++];
        }
        /*Ab hum writer_main ko writer_reader++ kar da ga us ki waja ya ha k ku k wasa bhi ya hona tha agr hum if conition ma bhi likhta tab bhi ya hona tha ku k
        ya jab main array ma write karta jaya ga to zahir thi jab ha chiya if ho ya else ho is na writer_reader++ hi hona tha na ku k is sa aga chalta jana ha na*/
        //YA NICHA WALA HAR IF YA ELSE K BAD IK MARTABA CHALA GA
        writer_main++;
    }
        /*Ab jasa k is uper wali condition ki waja sa ik side yani Right_Array(Right side) ma sab main wala ma (arr) ma chala jaya ga lakn abhi bhi Left_Array(Left side) ma
        to wasa hi bacha ha ku k agr ik conition bhi ghalt hi to loop khtm samj a gi is waja sa abhi bhi us Left_Array ma values ha to us ka to koi comparison nhi ha na
        ku k ab to Right_Array ma ki value ha hi nhi is waja sa hum ik jaya loop lagaya ga  Left_Array k liya us k reader_LA ki madad sa kam kara ga*/
        while(reader_LA<n1)
        {
            /*Ab ya dakho is ma hum na Left_array ma sa uthaya ha or main wala ma rakh dia ha har kisi k apna reader or writer na kam kia or pher dono
            k reader or writer ko hum na ++ kia ku k ya aga bhatr jaya ga jasa phala ik na 5 ko read kia to dusra 5 ko write kar da ga asa dono chlata jaya ga
            lakn zarri nhi ha k Right_Array hi khali ho ya bas ik eample ha isi liya ku k huma nhi pata k phala kon sa khali ho ga isi waja sa hum na dono 
            Right_Array or Left_Array ko khali karna k liya alag alag sa lop banaya ga taka agr Right_Array khali nhi ha to wo ho jaya warna Left_Array*/
            arr[writer_main] = Left_Array[reader_LA];
            reader_LA++;
            writer_main++;
        }
        /*Ab dakho yaha per Right_Array k liya bhi laga di k agr is ma values ha to wo main array ma chali jaya*/
    while(reader_RA< n2)
    {
        arr[writer_main] = Right_Array[reader_RA];
        reader_RA++;
        writer_main++;
    }
    
}
//Ya ha asal functin jo torta ha array ko or isi ma hum na merge wala function bhi use kia ha ya torta jaya ga or khud ko call karta jaya ga or 
//   pher merge ko bola la ga k unha joro is liya
void Merge_Sort(int arr[],int Left ,int Right)
{
    /*Ya hum na ik condition lagai ku k agr ya aga torta jaya k 8 k 4 or 4 ka 2 or 2 ka 1 or isi tara ya torta jaya ga ya - ma chala jaya ga 
    
    jis ki waja sa program crash ho jaya ga us sa bachna k liya hum na usa kha k jab tum Left wala Right k barbr ho jawo ya us sa bara hona sa phala
    hum retrun kar mtlb return ka ya ha k wapas a jawo jis a ya khtm h jya ga or hamesha chalna sa bacha ga*/
if(Left >= Right)
 return;
 /*Ya ha wo main middle wala formula j batata ha k middle kon sa ha ya asa ha k ku k huma Left ka pata ha or Right wala ka bhi pata ha to us lahz sa
 dakh agr 0-7 ha to Left 0 ho ga or Right 7 to
 Middle =0+(7-0)/2 = 0+7/2 = 7/2 =3.5 
 ku k ya integer ha to is k liya 3 ho ga  */
 int Middle =Left + (Right - Left)/2;
 
 //Ya wala function hum na is liya dobara apply kia ku k ya Left sa middle wala hisa tak yani Left side per kam kara ga
 Merge_Sort(arr,Left,Middle);

 //Ya wala middle sa aga Right tak kam kara ga yani Right side per kam kara ga
 Merge_Sort(arr,Middle+1,Right);
 //Ya inha jora ga jo hum na phala function likha ha wo ha
 merge(arr,Left,Middle ,Right);
}
//____________________________________________________________________________________________________________________________________________
//____________________________________________________________________________________________________________________________________________

/*TO AB US K BAD BAKI SAME MAIN HA HAMARA FUNCTION OR HUM CONITION N-1 TAK RAKHTA HU KU K AGR 9 HA ELEMNT TO N KARA GA TO 9 TAK CHALA GA LAKN INDEX 
0 SA SHARU HOTA HA IS LIYA YA 10 BAN JAYA GA*/
int main()
{
  int n =8;
  int arr[10]={1,5,6,2,7,3,7,8,9};
  Merge_Sort(arr,0,n-1);
  for(int k =0;k<n;k++)
  {
      cout<<arr[k];
  }
  }