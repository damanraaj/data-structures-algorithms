#include<iostream>
#include<stack>
using namespace std;
class Que
{
    stack<int> s1,s2;
public:
    void enque(int x)
    {
        s1.push(x);
    }
    bool isempty()
    {
        return s1.empty();
    }
    int dequeue()
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int x=s2.top();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }
};
int main()
{
    Que q;
    cout<<"q.isempty()"<<q.isempty()<<"\n";
    q.enque(45);
    q.enque(53);
    q.enque(4);
    cout<<"q.isempty()"<<q.isempty()<<"\n";

    cout<<"deque()"<<q.dequeue();

    return 0;
}
