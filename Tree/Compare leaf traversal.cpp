// Question:
/*
Leaf traversal is sequence of leaves traversed from left to right. The problem is to check if leaf traversals of two given Binary Trees are same or not.
Expected time complexity O(n). Expected auxiliary space O(h1 + h2) where h1 and h2 are heights of two Binary Trees.

Examples: 

Input: Roots of below Binary Trees
         1            
        / \
       2   3      
      /   / \          
     4   6   7

          0
        /   \
       5     8      
        \   / \        
        4   6  7
Output: same
Leaf order traversal of both trees is 4 6 7     

Input: Roots of below Binary Trees
         0            
        / \
       1   2       
      / \       
     8   9   

         1
        / \
       4   3     
        \ / \        
        8 2  9

Output: Not Same
Leaf traversals of two trees are different.
For first, it is 8 9 2 and for second it is
8 2 9
*/

// Code:
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

void printleaf(BinaryTree *root, vector<int> &a) {
	if(root == NULL) {
		return;
	}
	
	if(root->left == NULL && root->right ==NULL) {
		a.push_back(root->value);
		return;
	}	
	printleaf(root->left,a);
	printleaf(root->right,a);
}

bool compareLeafTraversal(BinaryTree *tree1, BinaryTree *tree2) {
  vector<int> a,b;
	printleaf(tree1,a);
	printleaf(tree2,b);
	if(a.size() != b.size()) {
		return false;
	}
	for(int i=0;i<a.size();i++) {
		if(a[i] != b[i]) {
			return false;
		}
	}
	return true;
}
