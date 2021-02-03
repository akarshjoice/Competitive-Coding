// Question:
/*
Given a linked list of size N and a key. The task is to insert the key in the middle of the linked list.

Example 1:

Input:
LinkedList = 1->2->4
key = 3
Output: 1 2 3 4
Explanation: The new element is inserted
after the current middle element in the
linked list.
Example 2:

Input:
LinkedList = 10->20->40->50
key = 30
Output: 10 20 30 40 50
Explanation: The new element is inserted
after the current middle element in the
linked list and Hence, the output is
10 20 30 40 50.
 

Your Task:
The task is to complete the function insertInMiddle() which takes head reference and element to be inserted as the arguments. The printing is done automatically by the driver code.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 104
*/


// Code:
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// function to display the linked list
void display(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout<<endl;
}

Node* insertInMiddle(Node* head, int x);

int main()
{
    int T, n, x;
    cin>>T;
    while(T--)
    {
        cin>> n >> x;
        
        struct Node *head = new Node(x);
        struct Node *tail = head;
        
        for (int i=0; i<n-1; i++)
        {
            cin>>x;
            tail->next = new Node(x);
            tail = tail->next;
        }
        
        cin>> x;
        head = insertInMiddle(head, x);
        display(head);
    }
    return 0;
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

// function should insert node at the middle
// of the linked list
Node* insertInMiddle(Node* head, int x)
{   
    Node *tmp = new Node(x);
    if (head == NULL) {
        return tmp;
    }
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;
    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(fast == NULL) {
        Node *tmp1 = prev->next;
        prev->next = tmp;
        tmp->next = tmp1;
       
    } else {
        Node *tmp1 = slow->next;
        slow->next = tmp;
        tmp->next = tmp1;
    }
     return head;
    
    

}