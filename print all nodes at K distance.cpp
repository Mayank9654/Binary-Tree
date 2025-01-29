/*
Print all the Nodes at a distance of K from target node in Binary Tree 
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

void markParent(Node* root, map<Node*, Node*> &parent)
{
    parent[root]=NULL;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(temp->left!=NULL) 
        {
            q.push(temp->left);
            parent[temp->left]=temp;
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
            parent[temp->right]=temp;
        }
    }
}

void distanceK(Node* root, Node* target, int k)
{
    map<Node*, Node*> parent;
    markParent(root,parent);
    map<Node*,bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target]=true;
    int current_level=0;
    while (!q.empty())
    {
        int size = q.size(); 
        if (current_level++ == k) break;
        for(int i=0;i<q.size();i++)
        {
            Node* temp=q.front();
            q.pop();
            if(temp->left!=NULL&&visited[temp->left]!=true)
            {
                q.push(temp->left);
                visited[temp->left]=true;
            }
            if(temp->right!=NULL&&visited[temp->right]!=true)
            {
                q.push(temp->right);
                visited[temp->right]=true;
            }
            if(parent[temp]!=NULL&&visited[parent[temp]]!=true)
            {
                q.push(parent[temp]);
                visited[parent[temp]]=true;
            }
        }
    }
    while(q.size()!=0)
    {
        cout<<q.front()->data<<" ";
        q.pop();
    }
}

int main()
{
    Node* root=new Node(3);
    root->left=new Node(5);
    root->left->left=new Node(6);
    root->left->right=new Node(2);
    root->left->right->left=new Node(7);
    root->left->right->right=new Node(4);
    root->right=new Node(1);
    root->right->left=new Node(0);
    root->right->right=new Node(8);
    iterativePreOrder(root); cout<<endl;
    // map<Node*,Node*> mp;
    Node* target = root->right;
    distanceK(root,target,2);
}