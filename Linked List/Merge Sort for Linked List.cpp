// Question:
/*
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Example 1:

Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.
Example 2:

Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given
linked list , resultant will be
0->9->15.
Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)

Constraints:
1 <= T <= 100
1 <= N <= 105
*/


// Code:
// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends


/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */
   
 Node* sortedMerge(Node* head_A, Node* head_B)  
{   
    Node *curr1 = head_A;
    Node *curr2 = head_B;
    Node *prev = NULL;
    Node *head;
    while (curr1 != NULL && curr2  != NULL) {
        if(curr1->data < curr2->data) {
            if(prev == NULL) {
                head = curr1;
                prev = curr1;
                curr1= curr1->next;
            } else {
                prev->next = curr1;
                prev = curr1;
                curr1= curr1->next;
            }
        } else {
            if(prev == NULL) {
                head = curr2;
                prev = curr2;
                curr2= curr2->next;
            } else {
                prev->next = curr2;
                prev = curr2;
                curr2 = curr2->next;
            }
        }
    }
    if(curr1!=NULL) {
        prev->next = curr1;
    }
    if(curr2!=NULL) {
        prev->next = curr2;
    }
    return head;
}  

Node *get_middle(Node *head) {
    if (head == NULL) {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;
    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return prev;
}

Node* mergeSort(Node* head) {
    
    if(head != NULL && head->next != NULL) {
        
    Node *middle = get_middle(head);
    Node *next = middle->next;
    middle->next = NULL;
    Node *head_A = mergeSort(head);
    Node *head_B = mergeSort(next);
    return sortedMerge(head_A,head_B);
    } else {
        return head;
    }
    
}


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends