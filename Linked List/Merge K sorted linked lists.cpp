// Question:
/*
Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Example 1:

Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.
Example 2:

Input:
K = 3
value = {{1,3},{4,5,6},{8}}
Output: 1 3 4 5 6 8
Explanation:
The test case has 3 sorted linked
list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be
1->3->4->5->6->8.
Your Task:
The task is to complete the function mergeKList() which merges the K given lists into a sorted one. The printing is done automatically by the driver code.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)
Note: n is the maximum size of all the k link list

Constraints
1 <= K <= 103
*/

// Code:

// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

Node* mergeKLists(Node* arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
// } Driver Code Ends


/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
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
  
  
Node * mergeKLists(Node *arr[], int N)
{      Node *head = arr[0];
       for(int i=0;i<N-1;i++) {
           Node *curr = arr[i];
           while(curr->next != NULL) {
               curr = curr->next;
           }
               curr->next = arr[i+1];
       }
       return mergeSort(head);
       
}