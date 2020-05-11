#include<iostream>
using namespace std;
class node
{
public:
    int maxidx;
    int low,high;
    node*left,*right;
    node(int i,int j)
    {
        low=i;
        high=j;
        left=NULL;
        right=NULL;
        maxidx=high;
    }
};
node * insertnode(node*root,int i,int j)
{
    if(root==NULL)
    {
        return new node(i,j);
    }
    else
    {
        if(i<root->low)
        {
            root->left=insertnode(root->left,i,j);
        }
        else
        {
            root->right=insertnode(root->right,i,j);
        }
        root->maxidx=max(root->left!=NULL && root->left->maxidx,root->right!=NULL &&root->right->maxidx);

        return root;
    }
}
void inorder(node*root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->low<<" "<<root->high<<"\n";
        inorder(root->right);
    }
}
int main()
{
    node*head=NULL;
    int n,k,p;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k>>p;
        head=insertnode(head,k,p);
    }
    inorder(head);

    return 0;
}
