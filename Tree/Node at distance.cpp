// Question:

/*
Given a Binary Tree and a positive integer k. The task is to count all distinct nodes that are distance k from a leaf node. A node is at k distance from a leaf if it is present k levels above the leaf and also, is a direct ancestor of this leaf node. If k is more than the height of Binary Tree, then nothing should be counted.

Example 1:

Input:
        1
      /   \
     2     3
   /  \   /  \
  4   5  6    7
          \ 
          8
K = 2
Output: 2
Explanation: There are only two unique
nodes that are at a distance of 2 units
from the leaf node. (node 3 for leaf
with value 8 and node 1 for leaves with
values 4, 5 and 7)
Note that node 2
isn't considered for leaf with value
8 because it isn't a direct ancestor
of node 8.
Example 2:

Input:
          1
         /
        3
       /
      5
    /  \
   7    8
         \
          9
K = 4
Output: 1
Explanation: Only one node is there
which is at a distance of 4 units
from the leaf node.(node 1 for leaf
with value 9) 
Your Task:
You don't have to read input or print anything. Complete the function printKDistantfromLeaf() that takes root node and k as inputs and returns the number of nodes that are at distance k from a leaf node. Any such node should be counted only once. For example, if a node is at a distance k from 2 or more leaf nodes, then it would add only 1 to our count.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= N <= 105
*/

// Code:

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


int printKDistantfromLeaf(Node* node, int k);

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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s, ks;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, ks);
        int k=stoi(ks);
        cout<<printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//Node Structure
/*struct Node
{
	int key;
	Node *left, *right;
};*/

//This function returns the count of the total distinct nodes that are at a 
//distance k from leaf nodes.
vector<Node*> a;
unordered_set<Node*> st;
int printKDistantfromLeaf1(Node* root, int k)
{
    if(root->left == NULL && root->right==NULL) {
        a.push_back(root);
        if(a.size()-1>=k) {
            st.insert(a[a.size()-1-k]);
            
        }
        a.pop_back();
        return 0;
    } else {
        a.push_back(root);
        if(root->left != NULL)
            printKDistantfromLeaf1(root->left, k);
        if(root->right != NULL)
            printKDistantfromLeaf1(root->right, k);
        a.pop_back();
        return st.size();
        
    }
}

int printKDistantfromLeaf(Node* root, int k)
{
    a.clear();
    st.clear();
    return printKDistantfromLeaf1(root, k);
}