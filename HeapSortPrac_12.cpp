#include <iostream>
#include <utility>

using namespace std;
/*Sab sa phala hum ik function banaya ga heapify function ya function ko ap ya bhi kha sakta ha k ya parents ko un k bacho sa compare karta ha or
paresnt ko uper la ata ha jasa
                                     3      <------Level 0
                                    / \
                                   1   5    <------Level 1
                                  / \
                                 2   4      <------Level 2
       Ab is ma dakha sab sa uper wala jo hota ha wo parents hota ha or us k nicha us k child idr dakho sab sa bara elemnyt kia
       level 0 per ha sab a uper ha nhi na to huma sab sa uper elemnt jo ha wo 3 ha yani hum 3 ko 5 k sath swap kara ga Level 0 per hi index 0 ha
                                     5      <------Level 0
                                    / \
                                   1   3    <------Level 1
                                  / \
                                 2   4      <------Level 2
Ab dakho abhi bhi 1 jo ha wo 2 or 4 sa chota ha to huma in dono sa compare karna para ga yani childs ko parents k sath or jo bara ho ga wo uper aya ga
                                     5      <------Level 0
                                    / \
                                   4   3    <------Level 1
                                  / \
                                 2   1      <------Level 2
Ab dakho ya heapify ho gia ha mtlb apni shi jaga per a gia ha ab k sab lakn agr inha array ma fit kara to ya asa banta ha
                      [5  4  3  2  1]
         index---->    0  1  2  3  4
Ya sorted nhi ha ya ulta ha to huma is ko asa karna ha k ku k index 0 per sab sa bara ha to humha is ko akhri wala index k sath swap kar lana ha
                      [1  4  3  2 | 5]   <--------- swaped ho gia or 5 ko us ki jaga per lock kar dana ha ku k ya ab sorted hi ha
         index---->    0  1  2  3   4
Ab pher hum asa hi kara ga or dakha ga k heapify tree ma ya asa dikh raha ha
                                     1      <------Level 0
                                    / \
                                   4   3    <------Level 1
                                  /
                                 2          <------Level 2
Ab dakha tree ki tarteeb ghalt ho gi sab sa chota number sab sa uper chala gia to huma isa pher sa thk karna ha
                                     4      <------Level 0
                                    / \                                   Yad raha wasa yaha bhi ik array banta ha [4 1 3 2] lakn ya ba is  liya
                                   1   3    <------Level 1                ma na nhi likha taka zaida muskal na ho asal concept yahi ha k phala wo
                                  /                                       tree ma hi tarteb data ha pher array ma 0 index per ku k array 0 per Max
                                 2          <------Level 2                heap hota ha yani sab sa uper wala to is liya hum isa ab sa end yani root
                                                                          node k sath swap karta ha yad raha ok

Abhi bhi ya thk nhi hova hum dobara isa shi kara ga ku k 2 abhi bhi 1 sa bara ha
                                     4      <------Level 0
                                    / \
                                   2   3    <------Level 1
                                  /
                                 1          <------Level 2
Ab isa array ma dakhta ha
                      [4  2  3  1  |5]
         index---->    0  1  2  3   4
Ab hum pher dakhta ha k index 0 per jo ha usa sab sa end wala k sath wap karna ha ku k index 0 per sab sa chota elemnt hota ha to jab swap kia to
                      [1  2  3  |4   5]  <------Ab dakha hum na 5 k sath 4 ko bhi lock kar dia ha ya swap ho gai
         index---->    0  1  2   3   4
Isi tara baki bhi sara process chala ga
                  -----------------------------------------------------------------------------------------
                  |Is ma jo trees ma thk karna wala kam heapify kara ga or array ma jo sort karna wala kam|
                  |sorted heap wala function kara ga                                                      |
                  -----------------------------------------------------------------------------------------

parent_index_to_fix wala jo ha ya tree ma wo node ya jaga batata ha jis sa fix karna ha yahi agr is ma
                                     4      <------Level 0
                                    / \
                                   1   3    <------Level 1
                                  /
                                 2          <------Level 2
1 ki jaga sa thk karna ha na to wo ya index bataya ga
Isi tara size_of_heap ya bundry batata ha jasa
                      [1  2  3  |4   5]
Ab is ma sirf 3 index per kam karna ha yani 4 or 5 lock ho gia ha is per kam nhi karna ok */

void heapify(int arr[], int size_of_heap, int parent_index_to_fix)
{
    /*To ab huma sab sa phala apna heapify function k liya planing karni ho gi huma ya batana ho ga k sab sa bara kon ha mtlb paresnt kon sa ha hum kha
    sakta ha k max heap sab sa uper wala kon sa ha pher hm ya bhi batana para ga k in k left or right child kon sa ha ma ik trick batata hu
                                     1      <------Level 0
                                    / \
                                   2   3    <------Level 1
                                  / \
                                 4   5      <------Level 2
TRICK: Ab ap dakha k right side per sab k sab odd number ha r left per even ha ya bas ik trick ha khabhi khabhi kam karti ha bar bar nhi
To jasa k ma na phala bataya tha k jo  parent_index_to_fix ha wo index ko fi karna k liya use hota ha or hum isa hi sab sa bara elemnt samja ga
farz kara ga or pher hum ik left or ik right wala banaya ga */

    int largest = parent_index_to_fix;
    /*Ab is ma dakho ya hum left inde ka bataya ga yad raha number jo ha un ka nhi bataya ga mlb ya sab sa uper wala inde 0 per ha us k bad 1 per asa
    Index form                        Original number

       index[0]
                                             1      <------Level 0
        /      \                            / \
    index[1]   index[2]                    2   3    <------Level 1
      /    \                              / \
index[3]   index[4]                      4   5      <------Level 2

     Ab ap dakh sakta ha k ya index da ga na k number formula ya nicha wala to ab is k dakhna */

    int left = 2 * parent_index_to_fix + 1;
    int right = 2 * parent_index_to_fix + 2;

    /*Ab hum condition lagaya ga kia left wala right wala sa bara ha agr wo bara ha to mtlb ab largest wala left ha lakn phala hum ik saftey
    check lagaya ga asa na ho k left wala mojood bhi na ho ro hum wasa hi conition lagata raha or elemnt ko dhondta raha is sa hamar prohram crash ho
    jaya ga to ab conition khuch is tara lagaya ga
    Agr left wala chota ha size_of_heap wala sa yani size_of_heap wohi asal ha size jo locked elemnts k bad ata ha mtlb jab locked elment k ilava
    mtlb mara khana k mtlb ya ha k jaa phala total array ka size 5 tha ik lock hova 4 ho gia size pher ik lock hoa 3 ho gia is tara size jasa

                               index[0]

                               /      \
                          index[1]    index[2]

    Ab dakho ya size kam ho kar bas 3 ho gia [0 1 2] to ya bas wohi ha  AND left wala k index us largest jo phala tha us sa bhi bara
    ha to largest ab left hova*/
    if (left < size_of_heap && arr[left] > arr[largest])
    {
        largest = left;
    }
    // Ab isi tara baki bhi k phala check kia right k liya pher conition laga di AND k sath
    if (right < size_of_heap && arr[right] > arr[largest])
    {
        largest = right;
    }
    /*Ab hum na 2 conidtion lagai ha phali k agr ya left bacha sa bara ha or dsura hum na lagaya k kia ya right bacha sa bara ha lakn kia ho
    agr ya dono false ho or wo jo elemnt ya number ha wo khud hi in sab sa bara ho to to us k liya hum ik conition lagaya ga k kia jo largest
    wala ha kia ya khud hi to parent_index_to_fix nhi ha na agr nhi ha tab wo swap kara index 0 wala ko end wla k sath or pher tab heapif
    function ko dobara call kia*/
    if (largest != parent_index_to_fix)
    {
        swap(arr[parent_index_to_fix], arr[largest]);
        /*Ab ya hum na dbara call kia ku k ya ab dobara sa us tree ko thk kara ga or usi index sa start kara ga jaha sa start karna ha is liya hum is
        ko starting to us ki aal size da ga jo us waqat shrink ho jaya ga pher hum parent_index_to_fix ki jaga largest da ga ku k largest hi us
        k wo point ho ga jaha sa wo start kara ga */
        heapify(arr, size_of_heap, largest);
    }
}
//--------------------------------------------------------------------------------------------------------------------------------
/*Ab hum ik function banaya ga jo main function ha jo asal ma sort kara ga heapify is k helper ya worker ha asal ma*/
void heapSort(int arr[], int n)
{
    /*Ya ab bataya ga k kha sa sharu karna ha ya loop sort karna k liya to hum isa kha ga k jo index ha parent_index_to_fix wala
    yaha sa n/2-1 sa sahru karna ha i k mtlb ya ha k for example size ha 5 to n ho ga 5 yani 5/2-1 = 2-1 = 1 yani index 1 sa sharu karo or
    jab tak end wala node na a jaya 0 wala tab tak chala ya loop or dusra ya nicha sa uper ki tarf jaya ga ku k -- ha loop or pher function ko
    dobara call kara ga */
    for (int parent_index_to_fix = n / 2 - 1; parent_index_to_fix >= 0; parent_index_to_fix--)
    {
        heapify(arr, n, parent_index_to_fix);
    }
    /*Ab hum ik or loop ya Max heap ma sa ik ik elemnt nikala ga or usa lock karta jaya ga end ma or dusra is ma ya ho ga k ya array ko -- karta jaya
    ga yani shrink karta jaya ga
                             [1  2  3  |4   5]
    Ab is ma dakho 4 or 5 lock ho gia ha is ma ab bas 3 index ki jaga ra gi ha isi tara  */
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------
// Array ko print karna k liya function loop k zaria
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//---------------------------------------------------------------------------------------------------------------------------------------
/*Ya wohi main function jis ma hum ya functon use karta ha*/
int main()
{
    int arr[] = {4, 10, 3, 5, 1};
    // Bytes ki madad yani size ki madad sa number find karna array k size yani
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array is: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array is: ";
    printArray(arr, n);

    return 0;
}
