// Question:

/*
Given a Binary Tree of N nodes. Find the vertical width of the tree.

Example 1:

Input:
          1
       /    \
      2      3
     / \    / \
    4   5  6   7
            \   \
             8   9
Output: 6
Explanation: The width of a binary tree is
the number of vertical paths in that tree.



The above tree contains 6 vertical lines.
 

Example 2:

Input:
      1
    /  \
   2    3
Output: 3
 

Your Task:

You don't have to read input or print anything. Your task is to complete the function verticalWidth() which takes root as the only parameter, and returns the vertical width of the binary tree.

 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

 

Constraints:
1 <= Number of nodes <= 105
*/

// Code:

// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
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

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// your task is to complete this functionh
// function should return the width of the tree
int verticalWidth(Node* root);




 // } Driver Code Ends


//User function Template for C++

/*Structure of node of binary tree is as follows
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

int verticalWidth(Node* node)
{
  if(node == NULL) {
      return 0;
  }
  queue <pair<Node*,int>> q;
  q.push({node,0});
  unordered_set <int> st;
  while(q.empty() == false) {
      pair <Node*,int> p = q.front();
      q.pop();
      Node *root = p.first;
      int n = p.second;
      st.insert(n);
      if(root->left!=NULL) {
          q.push({root->left,n+1});
      }
      if(root->right != NULL) {
          q.push({root->right , n-1});
      }
  }
  return st.size();
}

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        
        cout << verticalWidth(root) << "\n";
    }


    return 0;
}
  // } Driver Code Ends