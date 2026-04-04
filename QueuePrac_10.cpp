#include <iostream>
//Ab hum ik standard library use kara ga jis sa ya already bana hova ha wo
#include <queue> 
using namespace std;
int main()
{
    /*Ab hum us queue jo STL ma sa nikali ha us ko ik nam da kar khali queue banaya ga jis ki data type bhi banaya ga
    Ya wasa hi ha jasa hum na python ma panda ko pd ka short nam dia*/
    queue<int> q;
    //Ab is ki madad sa hum elemnts enter kara ga sab sa pahaa wala elemnt ho ga ya jo phli line ha or us k bad wali us k bad jasa queue yani qatar ma hta ha
    q.push(10);
    q.push(20);
    q.push(30);
    //Ab check karta ha k is k size kia ha is k front elemnt kon sa ha or last wala kon sa ha
    cout<<"Size of queue is:"<<q.size()<<endl;
     cout<<"Front elemnt  of queue is:"<<q.front()<<endl;
      cout<<"Last element of queue is:"<<q.back()<<endl;


      /*Ab huma is ko print karna ha queue ma jo elemnts ha to us k liya hum ik loop lagaya ga while loop ya loop ki conidtion
      ya ho gi k jab tak ya queue khali nhi ha chalta raha or front elemnt ko print karo or usa pop yani bhari bhi nikalo*/

      /*Dakho wo kha raha ha phala k q.empy yani jab tak ya emppty ha lakn pher hum na not(!) laga kar isa ult kar dia yani jab tak khali nhi ha*/
      while(q.empty())
      {
        cout<<"Elemnts:"<<q.front()<<" ";
          q.pop();
      }
      cout<<endl;
      return 0;
}