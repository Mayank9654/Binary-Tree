/*
Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Input: root = [3,9,20,null,null,15,7]
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
    Node(int data1, Node* left1, Node* right1)
    {
        data=data1;
        left=left1;
        right=right1;
    }
};

int heightoftree(Node* root)
{
    if(root==NULL) return 0;
    return (max(heightoftree(root->left),heightoftree(root->right))+1);
}

void inordertraversal(Node* root, bool &ans)
{
    if(root==NULL) return;
    inordertraversal(root->left,ans);
    cout<<root->data<<" ";
    int leftheight=heightoftree(root->left);
    int rightheight=heightoftree(root->right);
    if(abs(leftheight-rightheight)>1) ans = ans && false;
    inordertraversal(root->right,ans);
}

int main()
{
    Node* root=new Node(3);
    root->left=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(17);
    root->right->right->right=new Node(6);
    bool ans=true;
    inordertraversal(root, ans);
    cout<<endl<<ans<<endl;
}