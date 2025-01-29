//height/depth of a binary tree
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

void maxdepthlevelordertraversal(Node* root) 
{
    int depth = 0;
    if (root == NULL) return;
    queue<Node*> q;
    Node* newRoot=root;
    q.push(newRoot);
    while (!q.empty()) 
    {
        depth++;
        for (int i = 0; i < q.size(); i++) 
        {
            Node* temp = q.front();
            q.pop();
            if (temp -> left != NULL) q.push(temp -> left);
            if (temp -> right != NULL) q.push(temp -> right);
        }
    }
    cout<<depth<<endl;
}

int maxdepth(Node* root)
{
    if(root==NULL)
    return 0;
    else 
    return (max(maxdepth(root->left),maxdepth(root->right))+1);
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
    maxdepthlevelordertraversal(root);
    cout<<maxdepth(root)<<endl;
}