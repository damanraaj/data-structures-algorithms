#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<class T>
void insertionsort(vector<T> *a,int n)
{
    int i,j;
    T t;
    for(i=1;i<n;i++)
    {
        j=i-1;
        t=(*a)[i];
        while(j>=0 && (*a)[j]>t)
        {
                (*a)[j+1]=(*a)[j];
                j--;
        }
        (*a)[j+1]=t;
    }
}
template<class T>
int interpolationsearch(vector<T>arr,int s,int e,int k)
{
    if(s<=e && k>=arr[s] &&k<=arr[e])
    {
        int m=s+ abs(((s-e-1) /(arr[e]-arr[s]))*(k - arr[s]));
        if(arr[m]==k)
            return m;
        else if(arr[m]<k)
        {
            return interpolationsearch(arr,m+1,e,k);
        }
        else if(arr[m]>k)
        {
            return interpolationsearch(arr,s,m-1,k);
        }

    }
    else
    {
        return -1;
    }

}
int main()
{
    int n,i;
    cin>>n;
    vector<int> arr(n);
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertionsort(&arr,n);
    //sort(arr,arr+i);

    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";

    cout<<"enter num to be found : ";
    cin>>i;
    cout<<interpolationsearch(arr,0,n-1,i);
    return 0;
}
