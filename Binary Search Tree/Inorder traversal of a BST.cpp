// Question:

/*
Inorder traversal means traversing through the tree in a Left, Node, Right manner. We first traverse left, then print the current node, and then traverse right. This is done recursively for each node.
Given a BST, find its in-order traversal.

Example 1:

Input:
       5
    /    \
   2      7
    \       \
    3        8
Output: 2 3 5 7 8

Example 2:

Input:
     30
     /
   10
     \
     20
Output: 10 20 30
Your Task:
You don't need to read input or print anything. Complete the function inOrder() that takes the root of the BST as input parameter and returns a list of integers containing the in-order traversal of the BST.

Expected Time Complexity: O(N), where N = Number of nodes in BST
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= Number of nodes <= 100
1 <= Value of a node <= 100
*/

// Code:

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNewNode(int value)
{
    Node *temp=new Node;
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}

Node *newNode(Node *root,int data)
{
    if(root==NULL)
    root=createNewNode(data);
    else if(data<root->data)
    root->left=newNode(root->left,data);
    else
    root->right=newNode(root->right,data);
    
    return root;
}


 // } Driver Code Ends


//User function Template for C++

/*
struct Node
{
    int data;
    Node *left;
    Node *right;
};
*/
void inorder1(Node *root, vector<int> &a)
{
    if(root == NULL) {
        return;
    }
    
    inorder1(root->left, a);
    a.push_back(root->data);
    inorder1(root->right, a);
}

// Return a vector containing the inorder traversal of the tree
vector<int> inOrder(Node* root)
{
  vector<int> a;
  if(root == NULL) {
        return a;
  }
  
  inorder1(root, a);
  return a;
}

// { Driver Code Starts.


int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *root=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];
        
        for(int i=0;i<sizeOfArray;i++)
        {
            root=newNode(root,arr[i]);
        }
        
        vector <int> res = inOrder(root);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout << endl;
    }
	return 0;
}  // } Driver Code Ends