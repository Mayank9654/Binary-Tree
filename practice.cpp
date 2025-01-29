// #include <bits/stdc++.h>
// using namespace std;
// class Node 
// {
//     public:
//     int data;
//     Node* left;
//     Node* right;
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
// // void display(vector<vector<int>>a)
// // {
// //     for(int i=a.size()-1;i>=0;i--)
// //     {
// //         for(int j=0;j<a[i].size();j++)
// //         {
// //             cout<<a[i][j]<<" ";
// //         }
// //         cout<<endl;
// //     }
// //     cout<<endl;
// // }

// // void display1(vector<vector<int>>a)
// // {
// //     for(int i=0;i<a.size();i++)
// //     {
// //         for(int j=0;j<a[i].size();j++)
// //         {
// //             cout<<a[i][j]<<" ";
// //         }
// //         cout<<endl;
// //     }
// //     cout<<endl;
// // }

// // void display2(vector<int> a)
// // {
// //     for(int i=0;i<a.size();i++)
// //     {
// //         cout<<a[i]<<" ";
// //     }
// //     cout<<endl;
// // }
// // void levelOrderBottom(Node* root) 
// //     {
// //         vector<vector<int>>ans, res;
// //         if(root==NULL) return ;
// //         queue<Node*>q;
// //         q.push(root);
// //         while(true)
// //         {
// //             int size=q.size();
// //             if(size==0) return ;
// //             vector<int>level;
// //             while(size!=0)
// //             {
// //                 Node* temp=q.front();
// //                 q.pop();
// //                 level.push_back(temp->data);
// //                 if(temp->left!=NULL) q.push(temp->left);
// //                 if(temp->right!=NULL) q.push(temp->right);
// //                 size--;
// //             }
// //             ans.push_back(level);
// //         }
// //         for(int i=0;i<ans.size();i++)
// //         {
// //             display2(ans[i]);
// //             // res.push_back(ans[i]);
// //         }
// //         // reverse(ans.begin(),ans.end());
// //         // return ans;
// //     }

//  int number(vector<int>a)
//     {
//         int num=0;
//         for(int i=0;i<a.size();i++)
//         {
//             num=num*10+a[i];
//         }
//         return num;
//     }
    
//     bool treepath(Node* root)
//     {
        
//     }

//     int sumNumbers(Node* root) 
//     {
//         if(root==NULL) return;
//     }

// void preorder(Node* root)
// {
//     if(root==NULL) return;
//     stack<Node*> st;
//     st.push(root);
//     while(!st.empty())
//     {
//         Node* temp=st.top();
//         st.pop();
//         cout<<temp->data<<" ";
//         if(temp->right!=NULL) st.push(temp->right);
//         if(temp->left!=NULL) st.push(temp->left);
//     }
// }

// int main()
// {
//     Node* root=new Node(3);
//     root->left=new Node(9);
//     root->right=new Node(20);
//     root->right->left=new Node(15);
//     root->right->right=new Node(7);
//     preorder(root); cout<<endl;
//     levelOrderBottom(root);
//     // display1(ans);
//     // nextsmallerelement(a);
//     // cout<<largestRectangleArea(a)<<endl;
// }