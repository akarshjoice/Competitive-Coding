// Question:

/*
Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

Example 1:

Input:
      5
    /   \
   1     7
    \
     2 
      \
       3
X = 3
Output: 3
Explanation: We find 3 in BST, so ceil
of 3 is 3.
Example 2:

Input:
     10
    /  \
   5    11
  / \ 
 4   7
      \
       8
X = 6
Output: 7
Explanation: We find 7 in BST, so ceil
of 6 is 7.
Your task:
You don't need to read input or print anything. Just complete the function findCeil() to implement ceil in BST which returns the ceil of X in the given BST.

Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= Number of nodes <= 105
1 <= Value of nodes<= 105
*/

// Code:

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
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
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

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
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

int findCeil(Node* root, int input);



int main()
{

	int t;
	scanf("%d ", &t);
	while (t--)
	{
		string s;
		getline(cin >> ws, s);
		int x;
		cin >> x;
		Node* root = buildTree(s);
		cout << findCeil(root, x) << endl;
	
	}
	return 1;
}





// } Driver Code Ends


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
};
*/

// Function to find ceil of a given input in BST. If input is more 
// than the max key in BST, return -1 
int findCeil(Node* root, int key) 
{ 
	if(root == NULL) {
	    return -1;
	}
	Node *curr = root;
	int val = -1;
	while(curr != NULL) {
	    if(val == -1 && (key < curr->data)) {
	        val = curr->data;
	        
	    } else if((key < curr->data) && val > curr->data) {
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