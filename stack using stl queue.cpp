#include<iostream>
#include<queue>
#include<iterator>
using namespace std;

class MyStack
{
    queue<int> q;
public:
    void push(int x)
    {
        q.push(x);
    }
    bool isempty(){return q.empty();}
    int pop()
    {
        int out;
        int i=0,n;
        n=q.size();
        while(i<n-1)
        {
            q.push(q.front());
            q.pop();
            i++;
        }
        out=q.front();
        q.pop();
        return out;
    }

};
int main()
{
    MyStack s1;
    cout<<s1.isempty()<<"\n";
    s1.push(4);
    s1.push(8);
    s1.push(2);
    s1.push(421);

    cout<<s1.isempty()<<"\n";

    while(!s1.isempty())
    {
        cout<<s1.pop()<<" ";
    }
    return 0;
}
