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

void preorder(Node* root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void bottomview(Node* root)
{
    if(root==NULL) return;
    map<int,int> mp;
    queue<pair<Node*, int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        auto temp=q.front();
        q.pop();
        Node* newNode=temp.first;
        int hd=temp.second;
        mp[hd]=newNode->data;
        if(newNode->left!=NULL) q.push({newNode->left,hd-1});
        if(newNode->right!=NULL) q.push({newNode->right,hd+1});
    }
    for(auto iter=mp.begin();iter!=mp.end();iter++)
    {
        cout<<(iter->second)<<" ";
    }
    cout<<endl;
}


int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->left->left=new Node(6);
    root->left->left->right=new Node(7);
    root->right->left=new Node(8);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;   
    postorder(root);
    cout<<endl;
    bottomview(root);
}