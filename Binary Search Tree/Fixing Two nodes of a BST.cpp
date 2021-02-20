// Question:

/*
Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed than the given input will form BST, except for 2 nodes that will be wrong.
 
Example 1:
Input:
       10
     /    \
    5      8
   / \
  2   20
Output: 1
Explanation:
 
Example 2:

Input:
         11
       /    \
      3      17
       \    /
        4  10
Output: 1 
Explanation: 
By swapping nodes 11 and 10, the BST 
can be fixed.
Your Task:
You don't need to take any input. Just complete the function correctBst() that takes root node as parameter. The function should return the root of corrected BST. BST will then be checked by driver code and 0 or 1 will be printed.

Expected Time Complexity : O(n)
Expected Auxiliary Space : O(1)
 
Constraints:
1 <= Number of nodes <= 1000
*/


// Code:

// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

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

bool isBST(Node* n, int lower, int upper)
{
    if(!n) return true;
    if( n->data <= lower || n->data >= upper ) return false;
    return (  isBST( n->left, lower, n->data )  &&  isBST( n->right, n->data, upper )  );
}

bool compare( Node* a, Node* b, vector<pair<int,int>> &mismatch )
{
    if( !a && !b ) return true;
    if( !a || !b ) return false;
    
    if( a->data != b->data )
        mismatch.push_back( pair<int,int> (a->data,b->data) );
    
    return ( compare( a->left, b->left, mismatch ) && compare( a->right, b->right, mismatch ) );
}

struct Node *correctBST( struct Node* root );

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        
        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);
        
        root = correctBST(root);
        
        // check 1: is tree now a BST
        if( ! isBST(root, INT_MIN, INT_MAX) )
        {
            cout<< "0\n";
            continue;
        }
        
        // check 2: comparing with duplicate tree
        
        vector<pair<int,int>> mismatch;
        // a vector to store data of mismatching nodes
        
        if( ! compare( root, duplicate, mismatch) )
        {
            // false output from this function indicates change in structure of tree
            cout<< "0\n";
            continue;
        }
        
        // finally, analysing the mismatching nodes
        if( mismatch.size() !=2 || mismatch[0].first!=mismatch[1].second || mismatch[0].second!=mismatch[1].first )
            cout<<"0\n";
        else cout<<"1\n";
    }
	return 0;
}
// } Driver Code Ends


/*Complete the function
Node is as follows:

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int x){
        int data = x;
        left = right = NULL;
    }
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

void inorder2(Node *root,int first, int second)
{
    if(root == NULL) {
        return;
    }
    
    inorder2(root->left, first,second);
    if(root->data == first) {
        root->data = second;
    }
    else if(root->data == second) {
        root->data = first;
    }
    inorder2(root->right, first,second);
}

struct Node *correctBST( struct Node* root )
{
    vector <int> a;
    inorder1(root,a);
    int first,second;
    int flag =0;
    for(int i=0;i<a.size();i++) {
        if(a[i-1]>a[i] && flag == 0) {
            first = a[i-1];
            second = a[i];
            flag = 1;
        }
        else if(a[i-1] > a[i] && flag == 1) {
            second = a[i];
        }
    }
    inorder2(root, first, second);
    
    return root;
    
}