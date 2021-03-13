// Question:
/*
We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
 

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.
*/


// Code:
#include <bits/stdc++.h>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};



vector<int> findNodesDistanceK(BinaryTree *tree, int target, int k) {
	vector <int> a;
	queue <BinaryTree*> q;
	q.push(tree);
	unordered_map <BinaryTree*,BinaryTree*> parent;
	parent.insert({tree, NULL});
	BinaryTree* start;
	while(q.empty() == false) {
		int n = q.size();
		for(int i=0;i<n;i++) {
			BinaryTree* tmp = q.front();
			q.pop();
			if(tmp->value == target) {
				start = tmp;
			}
			if(tmp->left != NULL) {
				parent.insert({tmp->left,tmp});
				q.push(tmp->left);
			}
			if(tmp->right != NULL) {
				parent.insert({tmp->right,tmp});
				q.push(tmp->right);
			}			
		}
	}
	
	unordered_map <BinaryTree*,int> visited;
	
  queue <pair<BinaryTree*, int>> p;
	p.push({start,0});
	
	while(p.empty() == false) {
		int n = p.size();
		for(int i=0;i<n;i++) {
			pair<BinaryTree*,int> tmp = p.front();
			BinaryTree* tmpNode = tmp.first;
			int dist = tmp.second;
			p.pop();
			if(dist == k) {
				a.push_back(tmpNode->value);
			}
			visited[tmpNode]++;
			if(tmpNode->left != NULL && visited.count(tmpNode->left) == 0) {
				p.push({tmpNode->left,(dist+1)});
			}
			if(tmpNode->right != NULL && visited.count(tmpNode->right) == 0) {
				p.push({tmpNode->right,(dist+1)});
			}
			if(parent[tmpNode] != NULL && visited.count(parent[tmpNode]) == 0) {
				p.push({parent[tmpNode],(dist+1)});
			}
		}
	}
	return a;
	
  
}
