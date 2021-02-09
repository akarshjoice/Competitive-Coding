// Question:

/*
Given a Binary Search Tree and a node value X. Delete the node with the given value X from the BST. If no node with value x exists, then do not make any change. 

Example 1:

Input:
      2
    /   \
   1     3
X = 12
Output: 1 2 3
Explanation: In the given input there
is no node with value 12 , so the tree
will remain same.
Example 2:

Input:
            1
             \
              2
                \
                 8 
               /    \
              5      11
            /  \    /  \
           4    7  9   12
X = 9
Output: 1 2 4 5 7 8 11 12
Explanation: In the given input tree after
deleting 9 will be
             1
              \
               2
                 \
                  8
                 /   \
                5     11
               /  \     \
              4    7     12
Your Task:
You don't need to read input or print anything. Your task is to complete the function deleteNode() which takes two arguments. The first being the root of the tree, and an integer 'X' denoting the node value to be deleted from the BST. Return the root of the BST after deleting the node with value X. Do not make any update if there's no node with value X present in the BST.

Note: The generated output will be the inorder traversal of the modified tree.
 

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).
 

Constraints:
1 <= N <= 105
*/

// Code:

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



struct Node* deleteNode(struct Node* root, int key);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s; 
    getline(cin, s);
    Node* root1 = buildTree(s);
    getline(cin, s);
    int k = stoi(s);
    root1  = deleteNode(root1, k);
    vector<int> v;
    inorder(root1, v);
    for(auto i:v)
        cout << i << " ";
    cout << endl;
   }
   return 0;
}// } Driver Code Ends


/* The structure of a BST Node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the root of the modified BST after deleting the node with value X
Node *find(Node *root) {
    if(root == NULL) {
        return root;
    }
    root = root->right;
    while(root!=NULL && root->left!=NULL) {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root,  int X)
{
    Node *curr = root;
    Node *prev = NULL;
    while(curr != NULL) {
        if(X > curr->data) {
            prev = curr;
            curr = curr->right;
        } else if(X < curr->data) {
            prev = curr;
            curr = curr->left;
        } else {
            if(curr->left == NULL && curr->right == NULL) {
                if(prev == NULL) {
                    return NULL;
                }
                if(X>prev->data) {
                    prev->right =NULL;
                } else {
                    prev->left = NULL;
                }
            }
            else if(curr->left == NULL) {
                curr->data = curr->right->data;
                if(curr->right != NULL) {
                    curr->right = curr->right->right;
                    curr->left = curr->right->left;
                }
            } else if(curr->right == NULL) {
                curr->data = curr->left->data;
                if(curr->left != NULL) {
                    curr->right = curr->left->right;
                    curr->left = curr->left->left;
                }
            } else {
                Node *succ = find(curr);
                curr->data = succ->data;
                curr->right = deleteNode(curr->right, succ->data);
            }
            return root;
        }
    }
    return root;
}