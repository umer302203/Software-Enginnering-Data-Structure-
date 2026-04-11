#include <iostream>
#include <queue>
using namespace std;
 
int main()

{
queue <int> q;
q.push(10);
q.push(20);

cout<<"Size"<<q.size();

while(!q.empty())
{
    cout<<"fRONT ELEMNTS"<<q.front();
    q.pop();
}


}