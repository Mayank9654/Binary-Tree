/*
Iterative implementation of Preorder, Inorder and Postorder
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

void preorderIterative(Node* root)
{
    stack<Node*> st;
    if(root==NULL) return;
    st.push(root);
    while(!st.empty())
    {
        Node* newNode=st.top();
        st.pop();
        cout<<newNode->data<<" ";
        if(newNode->right!=NULL) st.push(newNode->right);
        if(newNode->left!=NULL) st.push(newNode->left);
    }
}

void inorderIterative(Node* root)
{
    stack<Node*> st;
    Node* newNode = root;
    while(true)
    {
        if(newNode!=NULL)
        {
            st.push(newNode);
            newNode=newNode->left;
        }
        else
        {
            if(st.empty()==true) break;
            newNode=st.top();
            st.pop();
            cout<<newNode->data<<" ";
            newNode=newNode->right;
        }
    }
}

/*
Postorder traversal - Iterative approach using 2 stacks
Steps : 
1. initial config : Take the root and put it in the 1st stack.
2. Now, take the top from the 1st stack and put it into the 2nd stack
3. After that, if the top in 2nd stack has left → add it in 1st stack. 
4. And if the top in 2nd stack has right → add it in the 1st stack.
5. Now again, take the top from the 1st stack and put it into the 2nd stack. 
6. Repeat step 2,3 & 4 untill 1st stack is empty.
7. Pop the element from the 2nd stack and print.
*/
void iterativePostorderusing2stack(Node* root)
{
    stack<Node*> st1, st2;
    Node* newRoot = root;
    st1.push(newRoot);
    if(newRoot == NULL) return;
    while(!st1.empty())
    {
        newRoot = st1.top();
        st1.pop();
        st2.push(newRoot);
        // Push left and Right child onto st1 if exists
        if(newRoot->left != NULL) st1.push(newRoot->left);
        if(newRoot->right != NULL) st1.push(newRoot->right);
    }
    while(!st2.empty())
    {
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}

/*
PostOrder Traversal - Iterative approach using 1 stack

Step 1: Check for base case that if the current node is null, return void function.
Step 2: Traverse the left subtree using a recursive postorder call on the left child.
Step 3: Traverse the right subtree using a recursive postorder call on the right child.
Step 4: Add the value of the current node to the postorder traversal array.This recursive 
approach implicitly uses the call stack to handle backtracking while exploring the tree nodes in a postorder manner.
 */

void iterativePostorderusing1stack(Node* root)
{
    if(root==NULL) return;
    Node* current=root;
    stack<Node*>st;
    while(current!=NULL||!st.empty())
    {
        if(current!=NULL)
        {
            st.push(current);
            current=current->left;
        }
        else
        {
            Node* temp=st.top()->right;
            if(temp==NULL)
            {
                temp=st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(!st.empty()&&temp==st.top()->right)
                {
                    temp=st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }
            else 
            {
                current=temp;
            }
        }
    }
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
    preorderIterative(root);
    cout<<endl;
    inorderIterative(root);
    cout<<endl;
    iterativePostorderusing1stack(root); cout<<endl;
    iterativePostorderusing2stack(root);
}