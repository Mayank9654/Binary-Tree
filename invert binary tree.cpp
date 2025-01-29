/*
Invert Binary Tree || Mirror Tree
Given the root of a binary tree, invert the tree, and return its root.

Example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
Input: root = [2,1,3]
Output: [2,3,1]

Example 3:
Input: root = []
Output: []
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

void inordertraversal(Node* root)
{
    if(root==NULL) return;
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}

Node* inverttree(Node* root)
{
    stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        Node* newNode=st.top();
        st.pop();
        if(newNode!=NULL)
        {
            st.push(newNode->left);
            st.push(newNode->right);
            swap(newNode->left,newNode->right);
        }
    }
    return root;
}

int main()
{
    Node* root=new Node(4);
    root->left=new Node(2);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right=new Node(7);
    root->right->left=new Node(6);
    root->right->right=new Node(9);
    inordertraversal(root);
    Node* newtree = inverttree(root);
    cout<<endl;
    inordertraversal(newtree);
}
