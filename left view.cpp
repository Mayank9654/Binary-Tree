/*
Binary Tree Left Side View
Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

Input: root = [1,2,3,null,5,null,4]
Output: [1,2,5]
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node()
    {
        left=nullptr;
        right=nullptr;
    }
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

void display(vector<vector<int>> a)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void display2(vector<int> a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

vector<int> leftview(Node* root) 
{
    vector<int> ans;
    queue<Node*>q;
    q.push(root);
    if(root == NULL) return ans;
    while(1)
    {
        int size = q.size();
        if(size==0) return ans;
        vector<int> level;
        while(size>0)
        {            
            Node* temp = q.front();
            q.pop();
            level.push_back(temp->data);
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
            size--;
        }
         //cout<<level[0]<<" ";
        // cout<<level[level.size()-1]<<" ";
        ans.push_back(level[0]);
    }
    return ans;
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->right=new Node(5);
    root->right=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(4);
    display2(leftview(root));
}