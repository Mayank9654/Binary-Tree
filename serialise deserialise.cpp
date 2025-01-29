/*
Serialize And Deserialize a Binary Tree

Problem Statement: Given a Binary Tree, design an algorithm to serialise and deserialise it. 
There is no restriction on how the serialisation and deserialization takes place. But it needs 
to be ensured that the serialised binary tree can be deserialized to the original tree structure. 
Serialisation is the process of translating a data structure or object state into a format that 
can be stored or transmitted (for example, across a computer network) and reconstructed later. 
The opposite operation, that is, extracting a data structure from stored information, is deserialization.

Example 1:
Input:Binary Tree: 1 2 3 -1 -1 4 5
Output:After Serialisation: 1,2,3,#,#,4,5,#,#,#,#, After Deserialization: (Original Tree Back)

Explanation:  Any algorithm that compresses this binary tree to a string which can be transmitted and 
from which the binary tree can be reconstructed later can be used. Here we have used a serialisation 
algorithm based on level order traversal where comma separates the nodes and # denotes null nodes.

Example 2:
Input:Binary Tree: 1 2 3 -1 4 5 -1
Output :After Serialisation: 1,2,3,#,4,5,#, After Deserialization: (Original Tree Back)

Explanation: Any algorithm that compresses this binary tree to a string which can be transmitted 
and from which the binary tree can be reconstructed later can be used. Here we have used a serialisation 
algorithm based on level order traversal where comma separates the nodes and # denotes null nodes. 
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

string serialize(Node* root)
{
    //convert a binary tree to string
    if(root==NULL) return "";
    string s="";
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(temp==NULL) s=s+"#,";
        else s=s+to_string(temp->data)+",";
        if(temp!=NULL) 
        //this is doen because in case left and right are null we are appending the #
        {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return s;
}

Node* deserialise(string a)
{
    if(a.size()==0) return NULL;
    stringstream s(a);
    string str;
    getline(s,str,',');
    Node* root=new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#") temp->left=NULL;
        else{
            Node* leftNode=new Node(stoi(str));
            temp->left=leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str=="#") temp->right=NULL;
        else
        {
            Node* rightNode=new Node(stoi(str));
            temp->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->left=new Node(4);
    root->right->right=new Node(5);
    iterativePreOrder(root); 
    string s=serialize(root);
    cout<<endl<<s<<endl;
    Node* recoveredtree=deserialise(s);
    iterativePreOrder(recoveredtree);
}