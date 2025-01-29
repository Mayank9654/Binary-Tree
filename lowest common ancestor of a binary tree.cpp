/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T 
that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
*/

#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
    int data;
    Node* left;
    Node* right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int data1) : data(data1), left(nullptr), right(nullptr) {}
    Node(int data1, Node* left1, Node* right1) : data(data1), left(left1), right(right1) {}
};

bool findPath(Node* root, vector<Node*> &path, Node* n)
{
    if (root == nullptr) return false;
    path.push_back(root);
    if (root == n) return true;
    if (findPath(root->left, path, n) || findPath(root->right, path, n)) return true;
    path.pop_back();
    return false;
}
    
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) 
{
    vector<Node*> path1, path2;
    if (!findPath(root, path1, p) || !findPath(root, path2, q)) 
        return nullptr;
    Node* ans = nullptr;
    for (int i = 0; i < path1.size() && i < path2.size(); i++) 
    {
        if (path1[i] == path2[i]) 
            ans = path1[i];
        else 
            break;
    }
    return ans;
}

Node* lowestCommonAncestorOptimised(Node* root, Node* p, Node* q) 
{
    if (root == NULL) return NULL;
    // If the current node is one of the nodes to be found, return it
    if (root == p || root == q) return root;
    // Recur for the left and right subtrees
    Node* lca1 = lowestCommonAncestorOptimised(root->left, p, q);
    Node* lca2 = lowestCommonAncestorOptimised(root->right, p, q);
    // If both sides return a non-null value, the current node is the LCA
    if (lca1 != NULL && lca2 != NULL) return root;
    // If only one side is non-null, return that side
    return (lca1 != NULL) ? lca1 : lca2;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    root->right->left = new Node(7);
    Node* p = root->left->left->left; 
    Node* q = root->right->left;     
    Node* lca = lowestCommonAncestor(root, p, q);
    if (lca != nullptr)
        cout << "Lowest Common Ancestor for "<<p->data<<" and "<<q->data<<" is: "<< lca->data << endl;
    else
        cout << "Lowest Common Ancestor not found" << endl;

    Node* lcaoptimised=lowestCommonAncestorOptimised(root,p,q);
    cout << "LCA for "<<p->data<<" and "<<q->data<<" is: "<< lcaoptimised->data << endl;
}