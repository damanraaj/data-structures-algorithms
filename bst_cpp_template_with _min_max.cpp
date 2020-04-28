#include <iostream>

using namespace std;
template <class T>
class BST{
    
    T data;
    BST<T> *left,*right;
    
public:
    BST<T>()
    {
        left=nullptr;
        right=nullptr;
    }
    BST<T>(T value)
    {
        data=value;
        left=nullptr;
        right=nullptr;
    }
    BST<T>*Insert(BST<T> *root, T value)
    {
        if(!root)
        {
            return new BST<T>(value);
        }
        if(value > root->data)
        {
            root->right=Insert(root->right,value);
        }
        else
        {
            root->left=Insert(root->left,value);
        }
        return root;
    }
    T max(BST *root)
    {
        BST<T> *curr=root;
        while(curr->right!=nullptr)
        {
            curr=curr->right;
        }
        return curr->data;
    }
    T min(BST *root)
    {
        BST<T> *curr=root;
        while(curr->left!=nullptr)
        {
            curr=curr->left;
        }
        return curr->data;
    }
	void Inorder(BST<T> *root) 
	{ 
		if(!root) 
		{ 
			return; 
		} 
		Inorder(root->left); 
		cout << root->data << endl; 
		Inorder(root->right); 
	}   
};
int main()
{
    BST<int> b,*root;
    root=b.Insert(root,50);
    b.Insert(root, 30); 
    b.Insert(root, 20); 
    b.Insert(root, 40); 
    b.Insert(root, 70); 
    b.Insert(root, 60); 
    b.Insert(root, 80);
    cout<<b.min(root)<<endl;
    cout<<b.max(root);
    return 0;
}
