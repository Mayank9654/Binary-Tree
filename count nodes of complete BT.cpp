/*
Count total Nodes in a COMPLETE Binary Tree | O(Log^2 N) Approach
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

int findleftheight(Node* node)
{
    int height=0;
    while(node!=NULL)
    {
        height++;
        node=node->left;
    }
    return height;
}

int findrightheight(Node* node)
{
    int height=0;
    while(node!=NULL)
    {
        height++;
        node=node->right;
    }
    return height;
}

int countNodes(Node* root)
{
    if(root==NULL) return 0;
    int lh=findleftheight(root);
    int rh=findrightheight(root);
    if(lh==rh) return (1<<lh)-1;
    return (1+countNodes(root->left)+countNodes(root->right));
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->left->left=new Node(8);
    root->left->left->right=new Node(9);
    root->left->right->left=new Node(10);
    root->left->right->right=new Node(11);
    root->right=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    iterativePreOrder(root); 
    cout<<endl<<countNodes(root)<<endl;
    // map<Node*,Node*> mp;
    // Node* target = new Node(5);
}