// Question:
/*
Given a binary tree, check if the tree can be folded or not. A tree can be folded if left and right subtrees of the tree are structure wise same. An empty tree is considered as foldable.
Consider the below trees:
(a) and (b) can be folded.
(c) and (d) cannot be folded.


(a)
       10
     /    \
    7      15
     \    /
      9  11
(b)
        10
       /  \
      7    15
     /      \
    9       11
(c)
        10
       /  \
      7   15
     /    /
    5   11
(d)
         10
       /   \
      7     15
    /  \    /
   9   10  12
 
Example 1:

Input:
     10
    /    \
   7     15
 /  \   /  \
N   9  11   N
Output:Yes
Example 2:

Input:
      10
    /    \
   7     15
 /  \   /  \
5   N  11   N
Output: No

Your Task:
The task is to complete the function isFoldable() that takes root of the tree as input and returns true or false depending upon whether the tree is foldable or not.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= n <= 103
1 <= data of node <= 104
*/

// Code:

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

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

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends


/* Returns true if the given tree is foldable */

/* A binary tree node has data, pointer to left child
and a pointer to right child */
/*struct node
{
    int data;
    struct node* left;
    struct node* right;
    
    node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
void preorder1(Node *root, vector<int> &a)
{
    if(root == NULL) {
        a.push_back(-1);
        return;
    }
    a.push_back(0);
    preorder1(root->left, a);
    preorder1(root->right, a);
}


vector <int> preorder(Node* root)
{ 
  vector<int> a;
  if(root == NULL) {
        return a;
  }
  
  preorder1(root, a);
  return a;
}

void inorder1(Node *root, vector<int> &a)
{
    if(root == NULL) {
        a.push_back(-1);
        return;
    }
    
    inorder1(root->left, a);
    a.push_back(0);
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

Node* mirror1(Node* root)
{
    if(root == NULL) {
        return NULL;
    }
    Node *tmp;
    Node* lt = mirror1(root->left);
    Node* rt = mirror1(root->right);
    root->left = rt;
    root->right = lt;
    return root;
}
int same(vector<int> a,vector<int> b) {
    if(a.size() != b.size()) {
        return 0;
    }
    for(int i=0;i<a.size();i++) {
        if(a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

bool IsFoldable(Node* root)
{   
    if(root == NULL) {
        return true;
    }
    if(root->left !=NULL && root->right!=NULL) {
        vector <int> t1 = preorder(root->left);
        vector <int> t2 = inOrder(root->left);
        
        vector <int> t3 = preorder(mirror1(root->right));
        vector <int> t4 = inOrder(mirror1(root->right));
        
        if(same(t1,t3) && same(t2,t4)) {
            return true;
        }
        return false;
     } else {
         if(root->left ==NULL && root->right ==NULL) {
             return true;
         } else {
             return false;
         }
     }
 
    
}

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        if (IsFoldable(root)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }

    }


    return 0;
}  // } Driver Code Ends