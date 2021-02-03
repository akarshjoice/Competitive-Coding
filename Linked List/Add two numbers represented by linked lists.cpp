// Question:
/*
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.        

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M))

Constraints:
1 <= N, M <= 5000
*/


// Code:
// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
struct Node* reverseList(struct Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while(curr != NULL) {
        Node *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}


struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    Node *tmp1 = reverseList(first);
    Node *tmp2 = reverseList(second);
    
    int carry = 0;
    int sum = 0;
    int flag = 0;
    Node *prev = NULL;
    Node *head;
    while(tmp1 != NULL && tmp2 !=NULL) {
        sum = tmp1->data + tmp2->data + carry;
        if(flag == 0) {
            head = new Node(sum%10);
            carry = sum/10;
            prev = head;
            flag =1;
        } else {
            Node *tmp = new Node(sum%10);
            carry = sum/10;
            prev->next = tmp;
            prev = tmp;
        }
        tmp1=tmp1->next;
        tmp2=tmp2->next;
    }
    while(tmp1!=NULL) {
        sum = tmp1->data + carry;
        Node *tmp = new Node(sum%10);
        prev->next = tmp;
        prev = tmp;
        carry = sum/10;
        tmp1=tmp1->next;
    } 
    while(tmp2 != NULL) {
        sum = tmp2->data + carry;
        Node *tmp = new Node(sum%10);
        prev->next = tmp;
        prev = tmp;
        carry = sum/10;
        tmp2 = tmp2->next;
    } 
    if(carry != 0) {
            Node *tmp = new Node(carry);
            prev->next = tmp;
            prev = tmp;
    }
    head = reverseList(head);
    return head;
    
}