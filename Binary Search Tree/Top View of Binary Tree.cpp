// Question:

/*
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Print from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
Your Task:
Since this is a function problem. You don't have to take input. Just complete the function printTopView() that takes root node as parameter and prints the top view. Print endline after end of printing the top view.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
1 <= Node Data <= 105
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

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

vector<int> topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        vector<int> res = topView(root);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
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
// function should print the topView of the binary tree
vector<int> topView(struct Node *root)
{
    vector <int> a;
    queue <pair<Node *,int>> q;
    map <int,int> mp;
    q.push({root,0});
    int n;
    while(q.empty() == false) {
        n = q.size();
        for(int i=0;i<n;i++) {
            pair <Node*,int> p = q.front();
            q.pop();
            if(mp.count(p.second) != 1)
                mp.insert({p.second, (p.first)->data});
            if((p.first)->left != NULL) {
                q.push({(p.first)->left,p.second-1});
            }
            if((p.first)->right != NULL) {
                q.push({(p.first)->right,p.second+1});
            }
        }
    }
    for(auto i:mp) {
        a.push_back(i.second);
    }
    return a;
}