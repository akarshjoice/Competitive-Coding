// Question:

/*
Given an array of size N that can be used to represents a tree. The array indexes are values in tree nodes and array values give the parent node of that particular index (or node). The value of the root node index would always be -1 as there is no parent for root. Construct the standard linked representation of Binary Tree from this array representation.

 

Example 1:

Input:
N = 7
parent[] = {-1,0,0,1,1,3,5}
Output: 0 1 2 3 4 5 6
Explanation: the tree generated
will have a structure like 
          0
        /   \
       1     2
      / \
     3   4
    /
   5
 /
6
 

Example 2:

Input:
N = 3
parent[] = {2, 0, -1}
Output: 2 0 1
Explanation: the tree generated will
have a sturcture like
               2
             /   
            0      
          /   
         1     
 

Your Task:
You don't need to read input or print anything. The task is to complete the function createTree() which takes 2 arguments parent[] and N and returns the root node of the constructed tree.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

// Code:

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

void sort_and_print(vector <int> &v)
{
    sort( v.begin() , v.end() );
    for( int i=0 ; i<v.size() ; i++ )
        cout<< v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root)
{
    vector <int> v;
    queue <Node*> q;
    
    q.push(root);
    
    Node* next_row = NULL;
    
    while(!q.empty())
    {
        Node* n = q.front();
        q.pop();
        
        if(n==next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }
        
        v.push_back(n->data);
        
        if(n->left)
        {
            q.push(n->left);
            if(next_row == NULL) next_row = n->left;
        }
        
        if(n->right)
        {
            q.push(n->right);
            if(next_row == NULL) next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

/* Driver program to test above function*/
int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        int a[n];
        for( int i=0 ; i<n ; i++ )
            cin>> a[i];
        
        struct Node *res = createTree(a,n);
        
        printLevelOrder(res);
        cout<<endl;
    }

    return 0;
}

// } Driver Code Ends


/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

/*  Function which returns the  root of 
    the constructed binary tree. */

Node *createTree(int parent[], int N)
{   
    unordered_map <int,Node*> mp;
    Node *head;
    for(int i=0;i<N;i++) {
        Node *tmp = new Node(i);
        mp.insert({i,tmp});
        if(parent[i] == -1) {
            head = tmp;
        }
    }
    
    for(int i=0;i<N;i++) {
        if(parent[i] == -1) {
            continue;
        }
        
        if(mp[parent[i]]->left == NULL) {
            mp[parent[i]]->left = mp[i];
        } else {
            mp[parent[i]]->right = mp[i];
        }
    }
    return head;
}