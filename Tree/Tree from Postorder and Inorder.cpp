// Question:

/*
Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to construct the binary tree from these traversals.

 

Example 1:

Input:
N = 8
in[] = 4 8 2 5 1 6 3 7
post[] =8 4 5 2 6 7 3 1
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder and
inorder traversal of tree the  resultant
binary tree will be
           1
       /      \
     2         3
   /  \      /  \
  4    5    6    7
   \
     8
 

Example 2:

Input:
N = 5
in[] = 9 5 2 3 4
post[] = 5 9 3 4 2
Output: 2 9 5 4 3
Explanation:  
the  resultant binary tree will be
           2
        /     \
       9       4
        \     /
         5   3
 

Your Task:
You do not need to read input or print anything. Complete the function buildTree() which takes the inorder, postorder traversals and the number of nodes in the tree as input parameters and returns the root node of the newly constructed Binary Tree.
The generated output contains the preorder traversal of the constructed tree.

 

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 103
1 <= in[i], post[i] <= 103
*/

// Code:

// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays
int findpos(int in[], int x, int n) {
    for(int i=0;i<n;i++) {
        if(in[i] == x) {
            return i;
        }
    }
}

int post_index = 0;
Node* build(int in[], int post[], int start, int end, int n) {
    if(start > end) {
        return NULL;
    } 
    if(post_index >= n) {
        return NULL;
    }
    Node *root = new Node(post[post_index++]);
    int pos = findpos(in, root->data, n);
    root->right = build(in, post, pos+1,end, n);
    root->left = build(in,post,start,pos-1, n);
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    int tmp;
    post_index = 0;
    for(int i=0;i<n/2;i++) {
        tmp = post[i];
        post[i] = post[n-i-1];
        post[n-i-1] = tmp;
    }
    return build(in,post, 0, n-1, n);
}