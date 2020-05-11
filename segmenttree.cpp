#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void buildSegTree(vector<int>vec,vector<int>&seg,int vstart,int vend,int ss)
{
    //cout<<ss<<" start,end "<<vstart<<" "<<vend<<"\n";
    if(vstart==vend)
    {
        //cout<<"ss"<<ss<<" n: "<<vec[vstart]<<"\n";
        seg[ss]=vec[vstart];
    }
    else
    {
        int mid=(vstart+vend)/2;
        buildSegTree(vec,seg,vstart,mid,2*ss);
        buildSegTree(vec,seg,mid+1,vend,2*ss+1);
        //cout<<"ss "<<ss<<" "<<seg[2*ss]<<"+"<<seg[2*ss+1]<<"\n";
        seg[ss]=seg[2*ss]+seg[2*ss+1];
    }
}
void maxSegTree(vector<int>vec,vector<int>&seg,int vstart,int vend,int ss)
{
    //cout<<ss<<" start,end "<<vstart<<" "<<vend<<"\n";
    if(vstart==vend)
    {
        //cout<<"ss"<<ss<<" n: "<<vec[vstart]<<"\n";
        seg[ss]=vec[vstart];
    }
    else
    {
        int mid=(vstart+vend)/2;
        buildSegTree(vec,seg,vstart,mid,2*ss);
        buildSegTree(vec,seg,mid+1,vend,2*ss+1);
        //cout<<"ss "<<ss<<" "<<seg[2*ss]<<"+"<<seg[2*ss+1]<<"\n";
        seg[ss]=max(seg[2*ss],seg[2*ss+1]);
    }
}
vector<int> segmentTree(vector<int> vec)
{
     int n=vec.size();
     vector<int> segtree(4*n);
     buildSegTree(vec,segtree,0,n-1,1);
     return segtree;
}
int getSum(vector<int> segtree,int vs,int ve,int s,int e,int i)
{
    if(vs<=s && ve>=e)
    {
        return segtree[i];
    }
    else if(vs>=s && ve<=e)
    {
        return 0;
    }
    else
    {
        int mid=(vs+ve)/2;
        return getSum(segtree,vs,mid,s,e,2*i)+getSum(segtree,mid+1,ve,s,e,2*i+1);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<vec.size();i++)
    {
        cin>>n;
        vec[i]=n;
    }
    vector<int> segtree=segmentTree(vec);
    for(int i=1;i<segtree.size();i++)
    {
        if(segtree[i])
            cout<<segtree[i]<<" ";
    }

    cout<<getSum(segtree,0,segtree.size(),2,5,1);
    return 0;
}
