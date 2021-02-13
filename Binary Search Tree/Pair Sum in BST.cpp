// Question:

/*
Given a BST and a number X. The task is to check if any pair exists in BST or not whose sum is equal to X.

Example 1:

Input:
      8
    /   \
   5     9
  / \
 1   3
X = 4
Output: 1
Explanation: For the given input, there
exist a pair whose sum is, i.e, (3,1).
Example 2:

Input:
      0
       \
        1
         \ 
          2
        /  \
       3    7
             \
              8
X = 6
Output: 0
Explanation: For the given input , there
exists no such pair whose sum is 6.
Your Task:
 Just write your code for the boolean function findPair() to check if a pair with given sum X exists in BST or not. The function returns true or false. The printing is done by the driver's code.

Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= Number of nodes <= 105
1 <= Value of the nodes <= 105
*/


// Code:

// { Driver Code Starts
// Initial Template for C++

// CPP program to find a pair with
// given sum using hashing
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}


bool findPair(Node* root, int sum);

// Driver code
int main() {

    int t;
    cin >> t;
    while (t--) {
        Node* root = NULL;
        int n, x;
        cin >> n;
        int val;
        for (int i = 0; i < n; i++) {
            cin >> val;
            root = insert(root, val);
        }
        cin >> x;
        if (findPair(root, x))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}// } Driver Code Ends


/* BST Node
struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

// This function should return true
// if there is a pair in given BST with
// given sum.
int pair1(Node* root, int X,map <int,int> &mp)
{
    if(root == NULL) {
        return 0;
    }
    if(pair1(root->left,X,mp) == 1) {
        return 1;
    }
    if(mp.count(X - root->data) == 1) {
        return 1;
    } else {
        mp.insert({root->data,0});
    }
    return pair1(root->right,X,mp);
    
}


bool findPair(Node* root, int X) {
    
    map <int,int> mp;
    if(pair1(root,X,mp)==1) {
        return true;
    } else {
        return false;
    }
}