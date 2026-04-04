
#include <iostream>
#include <queue>
using namespace std;
int main() {
 queue<int> q;

 q.push(10);
 q.push(20);
 q.push(30);

 cout << "Queue size: " << q.size() << endl;
 cout << "Front element: " << q.front() << endl;
 cout << "Rear element: " << q.back() << endl;

 
cout << "Elements: ";
 while (!q.empty()) {
 cout << q.front() << " ";
 q.pop();
 }
 cout << endl;

 return 0;
}
