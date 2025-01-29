/*
Morris Traversal
*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data1, Node* left1, Node*  right1)
    {
        data=data1;
        left=left1;
        right=right1;
    }
    Node(int data1)
    {
        data=data1;
        left=nullptr;
        right=nullptr;
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

void inorder_Morris_Traversal(Node* root)
{
    Node* current=root;
    while(current!=NULL)
    {
        if(current->left==NULL)
        {
            cout<<current->data<<" ";
            current=current->right;
        }
        else
        {
            Node* prev=current->left;
            while(prev->right!=NULL&&prev->right!=current)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                prev->right=current;
                current=current->left;
            }
            else
            {
                cout<<current->data<<" ";
                prev->right=NULL;
                current=current->right;
            }
        }
    }
}

void preorder_Morris_Traversal(Node* root)
{
    Node* current=root;
    while(current!=NULL)
    {
        if(current->left==NULL)
        {
            cout<<current->data<<" ";
            current=current->right;
        }
        else
        {
            Node* prev=current->left;
            while(prev->right!=NULL&&prev->right!=current)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                cout<<current->data<<" ";
                prev->right=current;
                current=current->left;
            }
            else
            {
                prev->right=NULL;
                current=current->right;
            }
        }
    }
}

void display(vector<int>a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void postorder_Morris_Traversal(Node* root)
{
    vector<int> res;
    Node* current=root;
    while(current!=NULL)
    {
        if(current->right==NULL)
        {
            res.push_back(current->data);
            current=current->left;
        }
        else
        {
            Node* predecessor=current->right;
            while(predecessor->left!=NULL&&predecessor->left!=current)
            {
                predecessor=predecessor->left;
            }
            if(predecessor->left==NULL)
            {
                res.push_back(current->data);
                predecessor->left=current;
                current=current->right;
            }
            else
            {
                predecessor->left=NULL;
                current=current->left;
            }
        }
    }
    reverse(res.begin(),res.end());
    display(res);
}

int main()
{
    Node* root=new Node(8);
    root->left=new Node(3);
    root->right=new Node(10);
    root->left->left=new Node(1);
    root->left->right=new Node(6);
    root->left->right->left=new Node(4);
    root->left->right->right=new Node(7);
    root->right->right=new Node(14);
    root->right->right->left=new Node(13);
    preorder(root); cout<<endl;
    preorder_Morris_Traversal(root); cout<<endl;
    inorder(root); cout<<endl;
    inorder_Morris_Traversal(root); cout<<endl;
    postorder(root); cout<<endl;
    postorder_Morris_Traversal(root); cout<<endl;
}