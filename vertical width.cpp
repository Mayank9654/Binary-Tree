/*
Vertical Width of a Binary Tree
Given a Binary Tree of N nodes. Find the vertical width of the tree.

Input:
          1
       /    \
      2      3
     / \    / \
    4   5  6   7
            \   \
             8   9
Output: 6
Explanation: The width of a binary tree is the number of vertical paths in that tree.
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

void inordertraversal(Node* root)
{
    if(root==NULL) return;
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}

//unique values of horizontal distance solution
unordered_set<int> st;
void horizonataldistancecalculation(Node* root, int hd)
{
    if(root!=NULL)
    {
        horizonataldistancecalculation(root->left,hd-1);
        st.insert(hd);
        horizonataldistancecalculation(root->right,hd+1);
    }
}

int verticalwidth1(Node* root)
{
    st.clear();
    horizonataldistancecalculation(root,0);
    return st.size();
}

//maximum minimum value of horizontal distance solution
int mindistance=INT_MAX,maxdistance=INT_MIN;
void minmaxhorizonataldistancevalue(Node* root, int hd) 
{
    if(root==NULL) return;
    minmaxhorizonataldistancevalue(root->left,hd-1);
    mindistance=min(mindistance,hd);
    maxdistance=max(maxdistance,hd);
    minmaxhorizonataldistancevalue(root->right,hd+1);
}
int verticalwidth2(Node* root) 
{
    if(root==NULL) return 0;
    minmaxhorizonataldistancevalue(root,0);
    return (maxdistance-mindistance+1);
}

int main()
{
    Node* root=new Node(1);
    root->right=new Node(3);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);
    root->left->right->left->left=new Node(7);
    inordertraversal(root);
    st.clear();
    cout<<endl<<verticalwidth1(root)<<endl;
    cout<<verticalwidth2(root)<<endl;
}

