/*
Print Root to Node Path in Binary Tree
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

bool getPath(Node* root, int k, vector<int> &a)
{
    if(root==NULL) return false;
    a.push_back(root->data);
    if(root->data==k) return true;
    if(getPath(root->left,k,a)||getPath(root->right,k,a)) return true;
    a.pop_back();
    return false;
}

void display(vector<int>a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int maxPathdown(Node* root, int &maximum)
{
    if(root==NULL) return 0;
    int left=max(0,maxPathdown(root->left,maximum));
    int right=max(0,maxPathdown(root->right,maximum));
    maximum=max(maximum,(left+right+root->data));
    return max(left,right)+root->data;
}

int maxPathSum(Node* root)
{
    int maximum=INT_MIN;
    maxPathdown(root,maximum);
    return maximum;
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->right=new Node(5);
    root->right=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(4);
    iterativePreOrder(root);
    cout<<endl<<maxPathSum(root)<<endl;
}