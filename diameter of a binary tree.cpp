/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
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

int height(Node* root)
{
    if(root==NULL) return 0;
    return (max(height(root->left),height(root->right))+1);
}

int diameter(Node* root)
{
    if(root==NULL) return 0;
    int d1 =  1+height(root->left)+height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
    return max(d1,max(d2,d3));
}

int ans=0;

int anotherapproach(Node* root)
{
    if(root==NULL) return 0;
    int leftheight=anotherapproach(root->left);
    int rightheight=anotherapproach(root->right);
    ans=max(ans,(1+leftheight+rightheight));
    return 1+max(leftheight,rightheight);
}

int main()
{
    Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->left->left=new Node(6);
    root->right->left=new Node(7);
    cout<<"Number of Nodes "<<diameter(root)<<endl;
    cout<<"Path length "<<diameter(root)-1<<endl;
    anotherapproach(root);
    cout<<ans<<endl;
}
