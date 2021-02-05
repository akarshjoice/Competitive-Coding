// Question:

/*
Given a Binary Tree, you need to find the maximum value which you can get by subtracting the value of node B from the value of node A, where A and B are two nodes of the binary tree and A is an ancestor of B. 

Example 1:

Input:
    5
 /    \
2      1
Output: 4
Explanation:The maximum difference we can
get is 4, which is bewteen 5 and 1.
Example 2:

Input:
      1
    /    \
   2      3
           \
            7
Output: -1
Explanation:The maximum difference we can
get is -1, which is between 1 and 2.
Your Task:
The task is to complete the function maxDiff() which finds the maximum difference between the node and its ancestor.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree.

Constraints:
1 <= Number of edges <= 104
0 <= Data of a node <= 105
*/

// Code:

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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


int maxDiff(Node *root);

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
        string s ;
        getline(cin, s);
        Node* root = buildTree(s);
        
        cout<<maxDiff(root)<<endl;
    }
    return 0;
}

// } Driver Code Ends


/* A binary tree node

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

/* Your are required to 
complete this method*/
int maxval = INT_MIN;
int maxDiff1(Node* root)
{   
    if(root->left == NULL && root->right == NULL) {
        return root->data;
    }
    int minval=INT_MAX;
    if(root->left !=NULL)
        minval = min(minval, maxDiff1(root->left));
    if(root->right != NULL)
        minval = min(minval,maxDiff1(root->right));
    if(minval != INT_MAX)
        maxval = max(root->data-minval,maxval);
    return min(minval,root->data);
}

int maxDiff(Node *root) 
{   
    if(root == NULL) {
        return -1;
    }
    maxval = INT_MIN;
    maxDiff1(root);
    return maxval;
} 