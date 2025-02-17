// /*
// Subtree of another Tree 
// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root 
// with the same structure and node values of subRoot and false otherwise.

// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. 
// The tree tree could also be considered as a subtree of itself.

// Example 1:
// Input: root = [3,4,5,1,2], subRoot = [4,1,2]
// Output: true

// Example 2:
// Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
// Output: false
// */

// #include <bits/stdc++.h>
// using namespace std;

// class Node 
// {
//     public:
//     int data;
//     Node* left;
//     Node* right;
//     Node()
//     {
//         left=nullptr;
//         right=nullptr;
//     }
//     Node(int data1)
//     {
//         data=data1;
//         left=nullptr;
//         right=nullptr;
//     }
//     Node(int data1, Node* left1, Node* right1)
//     {
//         data=data1;
//         left=left1;
//         right=right1;
//     }
// };

// void inorder(Node* root)
// {
//     if(root==NULL) return;
//     inorder(root->left);
//     cout<<root->data<<" ";
//     inorder(root->right);
// }

// bool ans;

// bool issubtree(Node* root, Noot* subroot)
// {
//     if(root!=NULL)
//     {
//         subtreecheck(root->left, subroot);
//         bool x = match(root, subroot);
//         if(x==true){ans = x;}
//         subtreecheck(root->right, subroot);
//     }
// }

// bool match(Node* root, Node* subroot)
// {
//     if(root!=NULL&&subroot!=NULL)
//     {
//         bool a=subtreecheck(root->left,subroot->left);
//         bool b=subtreecheck(root->right,subroot->right);
//         if(root->data==subroot->data && (a==true)&&(b==true)) 
//             return true;
//         else 
//             return false;
//     }
//     else if(root==NULL&&subroot==NULL) 
//         return true;
//     else 
//         return false;
// }

// int main()
// {
//     Node* root=new Node(1);
//     root->left=new Node(2);
//     root->right=new Node(3);
//     root->left->left=new Node(4);
//     root->left->right=new Node(5);
//     Node* subroot=new Node(2);
//     subroot->left=new Node(4);
//     subroot->right=new Node(5);
//     inorder(root);
//     cout<<endl;
//     inorder(subroot);
//     cout<<endl;
//     issubtree(root,subroot);
//     cout<<ans<<endl;
// }