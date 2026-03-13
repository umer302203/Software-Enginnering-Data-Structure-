#include <iostream>
#include <utility>
using namespace std;
/*Hum partition wala function is liya banaya ga ku k ya hi arrays ma pivt ko us ki asal jaga per la ata ha or arrays ko divide karta ha */
//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------
/*Acha ab nicha wala function k parameter dakho
Is ma jo arr[] ha wo asal ma wo array ha jo hum na input dana hota ha wo 8 wala or 10 wala [8,3,2,14,4,6,1,5]
Is ma jo low wala varibel ha wo asal ma us k sharu wala hisa ha ya index 0 hota ha
Is k ilava high wala sab sa end wala hisa hota ha
End ma int& pi ata ha is ma & is liya likhat ha taka is ki copy na bana agr cpy banti ha to asal array change /moidgy nhi ho ga
or pi hum na is liya banai ha ku k yahi asal ma pivot k us ki shi jaga per lata ha*/
void partition(int arr[], int low, int high, int &pi)
{
    /*Ab hum ik pivot banaya ga ya is liya banaya ga ku k hum sab sa last wala ko pivot select karna ha or yad ha tumha
    k hum na high banaya ku k jo high ha wo sab sa last wala ha yani uper wala arrya ma sa 5 wala sab sa last wala is liya
    hum pivot ko kha ga k ya sab sa last wala array ha*/
    int pivot = arr[high];
    /*Ab huma ik boundry wall banai ha yani ik asa varibel jo us array ki position ko yad rakh saga yad raha k ya wohi ha
    jo 0 index sa phala yani -1 per hota ha or j k pivot sa chota hona sa ya aga bharta ha yani index 0 per phala aya ga pher inde 1 per is tara aga*/
    int i = (low - 1);
    /*Ab hum ik loop lagaya ga ik asa loop jo j ho ga jo is pora array ko n-1 tak scan kara ga
    yani mara mtlb k n number of elemnts ha to hamara pas awasa bhi high ha jo end wala ha us sa phala wala
    tak scan kara ga yani high -1 tak */
    for (int j = 0; j <= high - 1; j++)
    {
        /*AB pher hum wohi conition laga da ga ku k huma ya pata ha k agr hamara j jo scaner ha wo pivot sa chota ha to i jo
        ha wo ik array aga a jaya yani i++ ho jaya or sath ma wo swap bhi kar da i ko j k sath
        MTLB ma samjta hu agr hamara ya ha [8,3,2,14,4,6,1,5] to jab i 8 per ho ga to j 3 per ho ga ab jab 3 ko dakha jaya ga k kia ya 5 sa chta ha agr ha
        to pher khuch nhi karna bas j ko ik aga move kar dana ha or sath ma j ko i k sath swap bhi kar dana ha yani  jo hamra 3 yani j ha wo swap ho jaya ga
        8 k sath mtlb 8 phala a jaya ga or 3 bad ma asa  [3,8,2,14,4,6,1,5] or sath ma j ik array aga bhi chala jaya ga */
        if (arr[j] <= arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        /*AB ya to ho gia lakn masla ya ha k abhi hum na sirf andar wala elemnt ko arrange kia ha hum na kis bhi pivot ko us ki shi position per nhi 
        la aya mtlb k agr asa ha na [1,2,3,14,,6,,5]  or is ma 5 pivot hajo abhi i 3 per ha to huma last wala yani jo pivot 5 ha usa i sa ik qadam
        aga la kar ana ha yani i+1 or jo elemnt ha jisa la kar jana ha wo i+1 hi ha or usa last wala k sath swap karna ha
        simple ma ya ha k jo hamara i sa aga wala ha yani i+1 wo pivot sa bara ha to usa hum na pivot yani high sa swap karna ha (yad raha k pivot sa swap
        nhi karna ha ku k pivot ka index change hota rahata ha) or us pi yani jo pivot ha us ki jaga bhi i+1 honi ha
        HUM pi is liya banaya ku k wo hamara quick sort k bataya ga k pivot ki asal inde kia ha is liya usa hum pie =i+1 kara ga */
        swap(arr[i+1],arr[high]);
        //Jasa k ma na phala bataya ha k ya quicksort function ko pivt ki asal location bataya ga mtlb pivot asal ma to i+1 ki jaga hi ho ga na is liya
        //mtlb simple ya us pivt ki asli jaga ka index ha
        pi =(i+1);
    }
}
/*Ab hum na ku k ya sab bana lia ha lakn huma isa print bhi to karwana ha na scren per to us k liya hum alag sa ik print function bana la ga
acha ab is function ko banaga ga is ma wasa to asa hota ha k hum print karwana k liya 2 paremeters chiya ik array h ga or ik us k size ku k hum na for
loop lagana ha or wo for loop hi us array ma sa ik ik elemnt nikal kar scren per print karwaya */
void print_Sort(int arr[],int size)
{
    for(int i = 0;i<=size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
/*Ab hum ik asa fucntion bana ha taka jab pivt ko asal poistion mil jaya to us k left or right dono side ko sort kia ja saga*/
void quick_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        /*Jasa k phala uper bataya ha k pi pivot ki asal position k index ko store karta ha or ya ik naya block ha to is k liya huma dobara
        sa batana para ga varibel ka  ku k varible jasa hu apna block sa niklna ha mtlb brackets sa to mar jata ha is liya int pi ki*/
        int pi;
        /*Ab hum partition wala function ko call kara ga array ko sort karna k liya is ma hum phala apna arr ko input da ga yani pora 6 number ka array
        us k bad low da ga low ki uper hum na conition dal di ha k ya low phala number ha index 0 ka  or high sab sa bara wala hota ha or pi jasa k 
        bataya ha k pivot ki original position ka index number ha*/
        partition(arr,low,high,pi);
        /*Ab hum isi function ko call kara ga taka wo partition wala ko dobara call kar saga is ma bhi same input asa hi ho ga k phala arr pher low mtlb sab 
        sa phala index wala pher pi-1 mtlb jo original pivot ha us ki position sa ik martaba phala mtlb ya pivot ki left side wala ho ga jasa 3 [5] 7 8 is ma
        ab 3 left side per ha na 5 yani pivot k to 3 per ya apply ho ga*/
        quick_sort(arr,low,pi-1);
        /*Ab ya right side wala k liya ho ga ya bhi wohi same usi tara k ya arr input la ga start ya pivot sa aga yani jasa 3 [5] 7 8 is ma sa 
        7 8 per apply h ga is ma hight end wala ha*/
        quick_sort(arr,pi+1,high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    /*Ab hum na ya sizeof wala opertor use kia ha ya opertor batat ha k is na kitna bytes data memory ma store ha mtlb jasa int wo 4 bytes store karta ha
    isi tara char 1 is tara baki bhi to ku k yaha hamara int ha or wo  4 bytes lata ha memory ma to us lahz sa humara arr jo ha us ma jitna bhi elemnts 
    ho ga un ko 4 sa multiply mtlb agr hamara arr ma 6 elemnts ha to har elemnt 4 bytes ka ho to 6x4=24 ho ga is lahz sa arr ma 24 bytes la ga
    pher hum is index 0 sa divide kara ga hum na ya is liya kia ku k inde 0 per koi ik elemnt to ho ga na or wo jitna bhi ho ga agr for example wo 
    5 ha to zahir si bat ha agr wo int ma ha t 4 bytes stre karta ha us lahz sa hum na 24/4 kia to 6 jawab aya mtlb is ma 6 elemnts ha n ma or ya 
    n ma store ho jaya ga*/
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array: ";
    print_Sort(arr, n);

    quick_sort(arr, 0, n - 1);

    cout << "Sorted array: ";
    print_Sort(arr, n);

    return 0;
}
