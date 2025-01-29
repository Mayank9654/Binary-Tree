/*
Flatten a binary tree to linked list
*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
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

void inorder(Node* root)
{
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

//recursion approach
class Solution 
{
public:
Node* prev=NULL;
void flattenapproach1(Node* root)
{
    if(root==NULL)
    {
       return;
    }
    flattenapproach1(root->right);
    flattenapproach1(root->left);
    root->right = prev;
    root->left = NULL;
    prev = root;
}
};
//stack approach
void flattenapproach2(Node* root)
{
    if(root==NULL) return;
    stack<Node*>st;
    st.push(root);
    while(!st.empty())
    {
        Node* temp=st.top();
        st.pop();
        if(temp->right!=NULL) st.push(temp->right);
        if(temp->left!=NULL) st.push(temp->left);
        if(!st.empty()) temp->right=st.top();
        temp->left=NULL;
    }
}

//Modified Morris Traversal approach
void flattenapproach3(Node* root)
{
    if(root==NULL) return;
    Node* temp=root;
    while(temp!=NULL)
    {
        if(temp->left!=NULL)
        {
            Node* prev=temp->left;
            while(prev->right!=NULL) prev=prev->right;
            prev->right=temp->right;
            temp->right=temp->left;
            temp->left=NULL;
        }
        temp=temp->right;
    }
}

void displaylinkedlist(Node* root)
{
	if(root==NULL) return;
	cout << root->data << " ";
	displaylinkedlist(root->right);
}

int main()
{
	Node* root=new Node(1);
	root->left=new Node(2);
	root->left->left=new Node(3);
	root->left->right=new Node(4);
	root->right=new Node(5);
	root->right->right=new Node(6);
	root->right->right->left=new Node(7);
	inorder(root);
	cout<<endl;
// 	Solution ob;
// 	ob.flattenapproach1(root);
    flattenapproach3(root);
	displaylinkedlist(root);
}