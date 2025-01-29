/*
Binary Tree Zigzag Level Order Traversal
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

or 

Input:
           10
         /     \
        20     30
      /    \
    40     60
Output: 10 20 30 60 40 
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

void display(vector<int> a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
}

void bfs(Node* root)
{
    queue<Node*> q;
    q.push(root);
    if(root==NULL) return;
    while(!q.empty())
    {
        //iterating for the queue size to include all the child nodes of a root node
        for(int i=0;i<q.size();i++) 
        {
            Node* newNode = q.front(); // Get the front node in the queue
            q.pop(); // Remove the front node from the queue
            cout<<newNode->data<<" ";
            if(newNode->left!=NULL) q.push(newNode->left);
            if(newNode->right!=NULL) q.push(newNode->right);
        }
    }
}

void display2(vector<vector<int>> a)
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

vector<vector<int>> levelorder(Node* root) 
{
    vector<vector<int>> ans;
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
        ans.push_back(level);
    }
    return ans;
}

vector<vector<int>> zigzagtraversal(Node* root) 
{
    vector<vector<int>> ans;
    queue<Node*>q;
    q.push(root);
    int index=0;
    if(root == NULL) return ans;
    while(1)
    {
        int size = q.size();
        if(size==0) return ans;
        vector<int> level;
        index++;
        while(size>0)
        {            
            Node* temp = q.front();
            q.pop();
            level.push_back(temp->data);
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
            size--;
        }
        if(index%2==0) {reverse(level.begin(),level.end());}
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->left = new Node(4);
    root->right->left=new Node(7);
    root->right->right=new Node(8);
    root->right->right->left=new Node(9);
    root->right->right->right=new Node(10);
    //bfs(root);
    //cout<<endl;
    display2(levelorder(root));
    display2(zigzagtraversal(root));
}