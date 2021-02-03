// Question:
/*
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
Your Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= N <= 105
*/


// Code:

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
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
/*You are required to complete this method */

struct Node* reverseList(struct Node *head)
{
    Node *tmp;
    if(head == NULL) {
        return head;
    }
    
    Node *pre = NULL, *curr = head;
    while(curr !=NULL) {
        tmp = curr->next;
        curr->next = pre;
        pre =curr;
        curr=tmp;
    }
    head = pre;
    return head;
    
}


bool isPalindrome(Node *head)
{
    Node *slow=head,*fast=head;
    while(fast != NULL && fast->next != NULL) {
        fast=fast->next->next;
        if(fast!=NULL) {
            slow=slow->next;
        }
    }
    slow->next = reverseList(slow->next);
    
    fast = slow->next;
    slow = head;
    while(fast!=NULL) {
        if(slow->data != fast->data) {
            return false;
        }
        slow=slow->next;
        fast=fast->next;
    }
    return true;
    
}