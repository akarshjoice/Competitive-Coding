// Question:

/*
Given a Binary search tree and a value X,  the task is to complete the function which will return the floor of x.

Note: Floor(X) is an element that is either equal to X or immediately smaller to X. If no such element exits return -1.

Example 1:

Input:
       8
     /  \
    5    9
   / \    \
  2   6   10
X = 3
Output: 2
Explanation: Floor of 3 in the given BST
is 2
Example 2:

Input:
       3
     /   \
    2     5
        /  \
       4    7
      /
     3
X = 1
Output: -1
Explanation: No smaller element exits
Your task:
You don't need to worry about the insert function, just complete the function floor() which should return the floor of X. If no such element exits return -1.

Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= Number of nodes <= 105
1 <= X, Value of Node <= 106
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

int floor(Node* root, int key) ;



int main() 
{
   
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
       string s ,ch;
       getline(cin, s);
       Node* root = buildTree(s);
       getline(cin, s);
       int x = stoi(s);

       int ans = floor(root, x);
       cout << ans << "\n";
   }
   return 0;
} // } Driver Code Ends


//User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};*/

/*This function is used to find floor of a key*/
int floor(Node* root, int key) 
{ 
	if(root == NULL) {
	    return -1;
	}
	Node *curr = root;
	int val = -1;
	while(curr != NULL) {
	    if(val == -1 && (key > curr->data)) {
	        val = curr->data;
	        
	    } else if((key > curr->data) && val < curr->data) {
	        val = curr->data;
	    }
	    if(key > curr->data) {
	        curr = curr->right;
	    } else if(key < curr->data) {
	        curr = curr->left;
	    } else {
	        return curr->data;
	    }
	}
	return val;
	

}