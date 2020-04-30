#include<iostream>
#include<stack>
using namespace std;
template<class T>
void displayStack(stack<T>*s)
{
    if(!s->empty())
    {
        T temp;
        temp=s->top();
        cout<<"| "<<temp<<" |\n";
        s->pop();
        displayStack(s);
        s->push(temp);
    }
}
template<class T>
void sortedInsertStack(stack<T>*s,T x)
{
    if(s->empty() || x>s->top())
    {
        s->push(x);
    }
    else
    {
        T z=s->top();
        s->pop();
        sortedInsertStack(s,x);
        s->push(z);
    }
}
template<class T>
void sortStack(stack<T>* s)
{
    if(!s->empty())
    {
        T temp=s->top();
        s->pop();
        sortStack(s);
        sortedInsertStack(s,temp);
    }
}
int main(void)
{
    int i;
    stack<int> st;
    while(cin>>i)
    {
        st.push(i);
    }
    displayStack(&st);
    sortStack(&st);
    cout<<"\n";
    displayStack(&st);
    return 0;
}
