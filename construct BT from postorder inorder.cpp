/*
Construct a Binary Tree from Postorder and Inorder Traversal
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

Node* buildTreePostIn(vector<int> inorder, int inStart, int inEnd, vector<int> postorder,int postStart, int postEnd, map<int,int>mp)
{
    if(inStart>inEnd||postStart>postEnd) return NULL;
    Node* root=new Node(postorder[postEnd]);
    int inRoot=mp[postorder[postEnd]];
    int numleft=inRoot-inStart;
    root->left=buildTreePostIn(inorder, inStart,inRoot-1,postorder,postStart,postStart+numleft-1,mp);
    root->right=buildTreePostIn(inorder, inRoot+1,inEnd,postorder,postStart+numleft,postEnd-1,mp);
    return root;
}

Node* buildTree(vector<int>inorder, vector<int>postorder)
{
    if(inorder.size()!=postorder.size()) return NULL;
    map<int,int> mp;
    for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
    return buildTreePostIn(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
}

int main()
{
    vector<int> postorder={40,50,20,60,30,10};
    vector<int> inorder={40,20,50,10,60,30};
    Node* root=buildTree(inorder,postorder);
    iterativeInorder(root); cout<<endl;
    iterativePostorder(root); cout<<endl;
    iterativePreOrder(root); cout<<endl;
}