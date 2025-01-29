/*
Construct a Binary Tree from Preorder and Inorder Traversal
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

Node* buildTree(vector<int>preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd, map<int, int>&mp)
{
    if(preStart>preEnd||inStart>inEnd) return NULL;
    Node* root= new Node(preorder[preStart]);
    int inRoot=mp[root->data];
    int numleft=inRoot-inStart;
    root->left=buildTree(preorder, preStart+1,preStart+numleft,inorder,inStart,inRoot-1,mp);
    root->right=buildTree(preorder, preStart+numleft+1,preEnd,inorder,inRoot+1,inEnd,mp);
    return root;
}

Node* build(vector<int> inorder, vector<int> preorder)
{
    map<int,int> mp;
    for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
    return buildTree(preorder, 0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
}

int main()
{
    vector<int> preorder={10,20,40,50,30,60};
    vector<int> inorder={40,20,50,10,60,30};
    Node* root=build(inorder,preorder);
    iterativeInorder(root); cout<<endl;
    iterativePostorder(root); cout<<endl;
    iterativePreOrder(root); cout<<endl;
}
