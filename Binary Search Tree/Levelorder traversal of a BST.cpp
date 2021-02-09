// Question:
/*
Levelorder traversal means traversing through the tree level by level, from left to right.
Given a BST, find its level-order traversal. 

Example 1:

Input:
      5
    /   \
   2     7
   \      \
    3      8
Output: 5 2 7 3 8

Example 2:

Input:
    30
   /
 10
   \ 
   20
Output: 30 10 20
Your Task:
You don't need to read input or print anything. Complete the function levelOrder() that takes the root of the BST as input parameter and returns a list of integers containing the level-order traversal of the BST.

Expected Time Complexity: O(N), where N = number of nodes in BST.
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 100
1 <= Value of a node <= 100
*/

// code:

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
vector<int> levelOrder(struct Node* root)
{
  vector <int> a;
  if(root == NULL) {
      return a;
  } 
  queue <Node*> q;
  q.push(root);
  int n;
  while(q.empty() == false) {
      n = q.size();
      for(int i=0;i<n;i++) {
          Node *curr = q.front();
          a.push_back(curr->data);
          q.pop();
          if(curr->left != NULL) {
              q.push(curr->left);
          }
          if(curr->right != NULL) {
              q.push(curr->right);
          }
      }
  }
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
        
        vector <int> res = levelOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
        
        
    }
	return 0;
}  // } Driver Code Ends