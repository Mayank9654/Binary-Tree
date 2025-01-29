/*
Check for Symmetrical Binary Trees
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

void iterativeInorder(Node* root)
{
    if(root==NULL) return;
    stack<Node*>st;
    Node* temp=root;
    while(true)
    {
        if(temp!=NULL)
        {
            st.push(temp);
            temp=temp->left;
        }
        else
        {
            if(st.empty()==true) break;
            temp=st.top();
            st.pop();
            cout<<temp->data<<" ";
            temp=temp->right;
        }
    }
}

void iterativePostorder(Node* root)
{
    if(root==NULL) return;
    stack<Node*>st1;
    stack<Node*>st2;
    Node* temp=root;
    st1.push(temp);
    while(!st1.empty())
    {
        temp=st1.top();
        st1.pop();
        st2.push(temp);
        if(temp->left!=NULL) st1.push(temp->left);
        if(temp->right!=NULL) st1.push(temp->right);
    }
    while(!st2.empty())
    {
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}

void iterativePreOrder(Node* root)
{
    if(root==NULL) return;
    stack<Node*>st;
    st.push(root);
    while(!st.empty())
    {
        Node* temp=st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right!=NULL) st.push(temp->right);
        if(temp->left!=NULL) st.push(temp->left);
    }
}

bool isSymetricHelp(Node* left,Node* right)
{
    if(left==NULL&&right==NULL) return true;
    if(left==NULL||right==NULL) return false;
    if(left->data!=right->data) return false;
    return (isSymetricHelp(left->left,right->right)&&isSymetricHelp(left->right,right->left));
}
bool isSymetric(Node* root)
{
    if(root==NULL) return true;
    return isSymetricHelp(root->left,root->right);
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->right=new Node(2);
    root->right->left=new Node(4);
    root->right->right=new Node(3);
    iterativePreOrder(root); 
    cout<<endl<<isSymetric(root)<<endl;
}