/*
You are given a binary tree, and your task is to return its top view. 
The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note: Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, 
consider the leftmost node only. 

Examples:
Input: root[] = [1, 2, 3] 
      1
    /   \
   2     3
Output: [2, 1, 3]

Input: root[] = [10, 20, 30, 40, 60, 90, 100]
       10
    /      \
   20       30
 /   \    /    \
40   60  90    100
Output: [40, 20, 10, 30, 100]
Explaination: 
The root 10 is visible.
On the left, 40 is the leftmost node and visible, followed by 20.
On the right, 30 and 100 are visible. Thus, the top view is 40 20 10 30 100.
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

void display(vector<int> a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

vector<int> topview(Node* root)
{
    vector<int> ans;
    if(root==NULL) return ans;
    map<int,int> mp;
    queue<pair<Node*, int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        auto temp=q.front();
        q.pop();
        Node* newNode = temp.first;
        int horizontaldistance=temp.second;
        if(mp.find(horizontaldistance)==mp.end()) mp[horizontaldistance]=newNode->data;
        if(newNode->left) q.push({newNode->left, horizontaldistance-1});
        if(newNode->right) q.push({newNode->right,horizontaldistance+1});
    }
    for(auto iter=mp.begin();iter!=mp.end();iter++)
    {
        ans.push_back(iter->second);
    }
    return ans;
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(9);
    root->left->right->left->left=new Node(12);
    root->left->right->left->left->left=new Node(20);
    root->right=new Node(3);
    root->right->right=new Node(6);
    root->right->right->left=new Node(8);
    display(topview(root));
}