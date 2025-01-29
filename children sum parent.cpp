/* 
Children Sum Parent 
Given a Binary Tree. Check whether all of its nodes have a value equal to the sum of their child nodes.

Input:
     10
    /
  10 
Output: 1
Explanation: Here, every node is the sum of its left and right child.
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

bool childrensumparent(Node* root)
{
    if((root==NULL)||(root->left==NULL&&root->right==NULL)) //Base Condition
    return 1;
    int leftsum=0,rightsum=0;
    if(root->left!=NULL)
    leftsum=root->left->data;
    if(root->right!=NULL)
    rightsum=root->right->data;
    if((root->data=leftsum+rightsum) && (childrensumparent(root->left)) && (childrensumparent(root->right)))
    return 1;
    else
    return 0;
}

int main()
{
    Node* root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(2);
    root->left->left=new Node(2);
    root->left->right=new Node(1);
    root->left->left->left=new Node(2);
    root->right->right=new Node(2);
    std::cout << childrensumparent(root) << std::endl;
}
