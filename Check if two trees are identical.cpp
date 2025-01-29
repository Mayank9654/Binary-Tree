/*
Same Tree | Determine if Two Trees are Identical 
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Input: p = [1,2,3], q = [1,2,3]
Output: true
*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node()
    {
        left=nullptr;
        right=nullptr;
    }
    Node(int data1)
    {
        data=data1;
        left=nullptr;
        right=nullptr;
    }
    Node(int data1, Node* left1,Node* right1)
    {
        data=data1;
        left=left1;
        right=right1;
    }
};

void display(vector<int>a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void inordertraversal(Node* root, vector<int> &a)
{
    if(root==NULL)
        return;
    inordertraversal(root->left,a);
    a.push_back(root->data);
    inordertraversal(root->right,a);
}

void preordertraversal(Node* root, vector<int> &a)
{
    if(root==NULL)
        return;
    a.push_back(root->data);
    preordertraversal(root->left,a);
    preordertraversal(root->right,a);
}

void identicaltree(Node* root1, Node* root2)
{
    vector<int> inorder1, inorder2, preorder1,preorder2;
    inordertraversal(root1,inorder1);
    inordertraversal(root2,inorder2);
    preordertraversal(root1,preorder1);
    preordertraversal(root2,preorder2);
    cout<<"Inorder Traversal for Tree1: "; display(inorder1);
    cout<<"Inorder Traversal for Tree2: "; display(inorder2);
    cout<<"Preorder Traversal for Tree1: "; display(preorder1);
    cout<<"Preorder Traversal for Tree2: "; display(preorder2);
    if(inorder1==inorder2&&preorder1==preorder2) cout<<"Identical Trees"<<endl;
    else cout<<"Not Identical"<<endl;
}

bool recursiveapproach(Node* root1, Node* root2)
{
    if(root1==NULL&&root2==NULL)
    return true;
    if(root1==NULL||root2==NULL)
    return false;
    return(root1->data==root2->data && recursiveapproach(root1->left,root2->left)&&recursiveapproach(root1->right,root2->right));
}

int main()
{
    Node* root1= new Node(1);
    root1->left = new Node(2);
    //root1->right=new Node();
    root1->right=new Node(3);
    Node* root2= new Node(1);
    //root2->left=new Node();
    root2->left = new Node(2);
    root2->right=new Node(3);
    identicaltree(root1, root2);
    cout<<recursiveapproach(root1, root2)<<endl;
}