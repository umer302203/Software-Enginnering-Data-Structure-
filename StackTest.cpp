#include <iostream>
using namespace std;
#define MAX 1000
class Stack
{
    public:
    int arr[MAX];
    int top;
    Stack()
    {
        top = -1;
    }
    bool push(int input)
    {
        if (top >= arr[MAX - 1])
        {
            cout << "Stack overflow" << endl;
            return false;
        }
        else
        {
            arr[++top] = input;
            cout << input << "Pushed into" << endl;
            return true;
        }
    }
    int pop()
    {
        if (top < 0)
        {
            cout << "Full" << endl;
        }
        else
        {
            int output = arr[--top];
            cout << output << "is out" << endl;
        }
    }
    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            return arr[top];
        }
    }
    bool isEmpty()
    {

        return (top < 0);
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    cout<<s.peek()<<endl;
    s.pop();
    while(!s.isEmpty())
    {
        s.pop();
        s.peek();
    }
}