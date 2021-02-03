// Question:

/*
Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:

Input:
N = 8
value[] = {1,2,3,4,5,6,7,8}
k = 4
Output: 5 6 7 8 1 2 3 4
Explanation:
Example 2:

Input:
N = 5
value[] = {2,4,7,8,9}
k = 3
Output: 8 9 2 4 7
Explanation:
Your Task:
You don't need to read input or print anything. Your task is to complete the function rotate() which takes a head reference as the first argument and k as the second argument, and returns the head of the rotated linked list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 103
1 <= k <= N
*/


// Code:

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node *rotate(struct Node *head, int k);

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        head = rotate(head,k);
        printList(head);
    }
    return 1;
}
// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function should rotate list counter-clockwise
// by k and return new head (if changed)
int getCount(struct Node* head){

    Node *curr;
    curr = head;
    int count = 0;
    while(curr != NULL) {
        count++;
        curr=curr->next;
    }
    return count;
}

Node* reverse(Node *head, int sindex, int eindex)
{
    Node *curr1 = head;
    int i=0;
    Node *prev1 = NULL;
    while(i<sindex) {
        prev1 = curr1;
        curr1 = curr1->next;
        i++;
    }
    i=0;
    Node *curr2 = head;
    while(i<eindex) {
        curr2 = curr2->next;
        i++;
    }
    Node *prev = NULL;
    Node *s = curr1;
    Node *r = curr2->next;
    while(curr1 != r) {
        Node *tmp = curr1->next;
        curr1->next = prev;
        prev = curr1;
        curr1 = tmp;
    }
    s->next = curr1;
    if(prev1 != NULL) {
        prev1->next = curr2;
    }
    if(sindex == 0) {
        return curr2;
    }
    return head;
}

Node* rotate(Node* head, int k)
{
    Node *curr = head;
    
    int n = getCount(head);
    k=k%n;
    head = reverse(curr,0,k-1);
    head = reverse(head,k,n-1);
    head = reverse(head,0,n-1);
    return head;
    
    
}
