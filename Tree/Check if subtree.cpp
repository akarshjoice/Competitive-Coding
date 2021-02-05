

// Question:

/*
Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

Example 1:

Input:
T:      1          S:   3
      /   \            /
     2     3          4
   /  \    /
  N    N  4
Output: 1 
Explanation: S is present in T

Example 2:

Input:
T:      26         S:   26
       /   \           /  \
     10     N        10    N
   /    \           /  \
   20    30        20  30
  /  \            /  \
 40   60         40  60
Output: 1 
Explanation: 
S and T are both same. Hence, 
it can be said that S is a subtree 
of T.
Your Task:
You don't need to read input or print anything. Your task is to complete the function isSubtree() that takes root node of S and T as parameters and returns 1 if S is a subtree of T else 0.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 105
1 <= Value of nodes <= 104
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

/*you are required to
complete this function */
bool isIdentical(Node *r1, Node *r2)
{
    if(r1 == NULL && r2 == NULL) {
        return true;
    }
    if(r1 == NULL || r2 == NULL) {
        return false;
    }
    if(r1->data == r2->data) {
       return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    } else {
        return false;
    }
    
}

void preorder1(Node *root, vector<int> &a)
{
    if(root == NULL) {
        a.push_back(-1);
        return;
    }
    a.push_back(root->data);
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

void computeLPSArray(vector<int> &pat, int M, vector<int> &lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool issubarray(vector<int> &txt, vector<int> &pat) {
    int M = pat.size();
    int N = txt.size();
    vector<int> lps(M);

    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            j = lps[j - 1];
            return true;
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return false;
} 
bool isSubTree(Node* T, Node* S) {
    
    vector <int> pT = preorder(T);
    vector <int> pS = preorder(S);
    vector <int> iT = inOrder(T);
    vector <int> iS = inOrder(S);
    if(issubarray(pT,pS) && issubarray(iT,iS)) {
        return true;
    }
    return false;
    
    
}

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Node *rootS = buildTree(strS);
        cout << isSubTree(rootT, rootS) << "\n";

    }


    return 0;
}  // } Driver Code Ends