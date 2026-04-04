#include <iostream>
using namespace std;
/*Acha ab hum ik varible type ki cheez banaya ga taka array ko size da aga us k liya kahli jaga bana saga t us k
liya hum define k word use kara ga */
#define Maximum_Space 1000
/*Ab ku k hum STL Container use nhi kar raha ha to us k liya hum ik class banaya ga jis sa isa ko use kar k kam kara ga*/
class Stack
{
    /*Hum ik top k nam ka variable banaya ga jis ma sab sa uper wala elemnt ho ga isa hum private rakha ga or isa
    hum constructor k zaria use karta ha jasa hum na phala pharhaa ha k kasa private varibels ko acces karta ha*/
    int top;

public:
    /*Ab hum class banata ha is class ma sab a phala hum apna array banaga or us ki jaga rakha ga mtlb hum sirf ik jaga bana raha ha*/
    int arr[Maximum_Space];
    /*Ab hum ik constructor banaya ga jasa hi hum ya class ko use kara ga wo khud hi run ho ga or pora array ko khali kar da ga
    Hum -1 use kara ga ku k -1 index nhi hota ha*/
    Stack()
    {
        top = -1;
    }
    /*Ab hum ik function banaya ga asa function k agr number dal gia to true retrun kara ga mtlb ho gia agr fail ho jaya number dalna ma to false
    retrun kar da ga is liya hum bool use kara ga or function banaya ga*/
    bool push(int input)
    {
        /*Ab hum phala ik safty check laga data ha ku k hum na 1000 ki jaga rakhi ha or huma pata ha k array ma 1000 ki jaga nhi hoti 999 ki jaga hoti
        ha ku k 0 sa index sharu hota ha */

        // Agr top wala Maximum_Space-1 sa bara ya brabra ha yani agr elment ha 998 or stack ma jaga total ha
        //  999 to to thk ha lakn agr asa nhi 1001 to ghalt

        if (top >= (Maximum_Space - 1))
        {
            cout << "Stack overflow" << endl;
            return false;
        }
        /*Agr conidtion uper wali false ho jaya yani agr jaga ha stack ma to pher tab hum is ma elemnt dala ga*/
        else
        {
            /*Ab hum asa kara ga k us array ma hamari input dal da ga to us k liya hum ik tarika chiya to hum asa kara ga
            k array ma jo top wala varibel ha jisa uper hum na -1 yani khali kia tha us ma ya input store kar da ga  or dusra hum apni is ma
            top sa phala ++ lagaya ga yani prefix taka jab bhi elemnt enter ho to ik place aga raha ku k ++ k mtlb bhi yahi ha k aga bharho or is ma
            ++top k mtlb ha k phala aga bharho pher ik enter karo
            Ya is liya hum na lagaya ha ku k hum na uper top = -1 kia tha or agr is ma dala to error a jaya ga is liya hum phala ++ yahi -1 sa ik qadam
            aga bharha ga us ma dala ga pher us sa ik qadam aga bharha ga is tara
               index----->      -1 0 1 2 3 4 5        ab dakho -1 ha to hum na 0 index per save karna ha isa */
            arr[++top] = input;
            cout << input << " pushed into stack" << endl;
            return true;
        }
    }
        /*Hum na ik jaga banai us ma array yani number ko fill karna ka function banaya ha hum na us ma saftey condition lagai k agr bhar jaya to kia karna ha
        Ab hum is stack ma elemnt ko bhair nikalna wala function banaya ga or ya asa kam kara ga k uper sa jo jo number ho ga unha nikala ga pop kara ga*/
        int pop()
        {
            /*Phla saftey check laga ga jasa phala uper wala function ma lagaya ha is ma hum ya check kara ga k kia ya already khali to nhi ha*
            is liya hum kha ga k agr top 0 sa chota ha yani khali ha */
            if (top < 0)
            {
                cout << "Stack underflow" << endl;
                return 0;
            }
            else
            // Agr uper wali conidtion ghalt hoi to pher ya
            {
                /*Ab hum na wo uper wala number nikalana ha to hum phala usa output wala ma save kara ga or jasa top ma hum na ++top kia idr hum picha
                ki tarf jaya ga yani -- kara ga or output ko return kara ga*/
                int output = arr[top--];
                return output;
            }
        }
        /*Ab hum na baki sab bana lia pop wala bhi bana lia ha stack bhi bana li ha us ki jaga or usa us ma dakhil karna ka tariak bhi lakn
        huma ya nhi pata k kon sa elemnt nikal raha ha wo kon sa ha is k liya hum peek wala function banaya ga*/
        int peek()
    {
        /*Ab jasa k batay ha phala safety check k kia ya khali to nhi ha is liya hum kha ga k kia top 0 sa chota ha
        yani kia ya khali ha pher return 0 kara ga*/
        if (top < 0)
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        else
        {
            //Agr khali nhi to arr[top] yani arr ma jo top ha us k nam retrun kara ga
            return arr[top];
        }
    }
    /*Ab hum ik fucntion banaya ga j ya bata da k kia ya khali ha or true or false return kara*/
    bool isEmpty()
    {
        /*Yani is nicha wala k mtlb ha k agr top 0 sa chota ha mtlb khali ha to true return karna warna fasle*/
        return (top < 0);
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    //Ya jo is ma pop or peek wala ha ya hum na jo function banaya tha ya wohi ha asal ma jisa hum na call ki 
    cout << s.pop() << " popped from stack" << endl;
    cout << "Top element is: " << s.peek() << endl;

   
    cout << "Elements present in stack: ";
    //Ya wohi k agr khali nhi ha ! ki symbol ha na mtlb not wali tab ya loop chala
    while (!s.isEmpty())
    {
        cout << s.peek() << " ";
        s.pop();
    }
    return 0;
}
