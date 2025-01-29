/*
Boundary Traversal in Binary Tree
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

bool isLeaf(Node* root)
{
    if(root->left==NULL&&root->right==NULL) return true;
    return false;
}

void addLeftBoundary(Node* root, vector<int>&a)
{
    Node* temp=root->left;
    while(temp!=NULL)
    {
        if(isLeaf(temp)==false) a.push_back(temp->data);
        if(temp->left!=NULL) temp=temp->left;
        else temp=temp->right;
    }
}

void addRightBoundary(Node* root, vector<int>&a)
{
    Node* temp=root->right;
    stack<int>st;
    while(temp!=NULL)
    {
        if(isLeaf(temp)==false) st.push(temp->data);
        if(temp->right!=NULL) temp=temp->right;
        else temp=temp->left;
    }
    while(!st.empty())
    {
        a.push_back(st.top());
        st.pop();
    }
}

void addLeaves(Node* root, vector<int>&a)
{
    if(isLeaf(root)) 
    {
        a.push_back(root->data); 
        return;
    }
    if(root->left!=NULL) addLeaves(root->left,a);
    if(root->right!=NULL) addLeaves(root->right,a);
}

vector<int> printBoundary(Node* root)
{
    vector<int>a;
    if(root==NULL) return a;
    if(isLeaf(root)==false) a.push_back(root->data);
    addLeftBoundary(root,a);
    addLeaves(root,a);
    addRightBoundary(root,a);
    return a;
}

void display(vector<int>a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(3);
    root->left->left->right=new Node(4);
    root->left->left->right->left=new Node(5);
    root->left->left->right->right=new Node(6);
    root->right=new Node(7);
    root->right->left=new Node(8);
    iterativePreOrder(root); cout<<endl;
    vector<int> a=printBoundary(root);
    display(a);
}