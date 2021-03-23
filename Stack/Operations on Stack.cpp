// Question:
/*
Given a stack of integers and Q queries. The task is to perform the operation on stack according to the query.

The queries can be of 4 types:

i x: (adds element x in the stack).

r: (removes the topmost element from the stack).

h: Prints the topmost element.

f y: (check if the element y is present or not in the stack). Print "Yes" if present, else "No".
 

Example 1:

Input: 
Q = 6 
Queries = {(i, 2), (i, 4), (i, 3),
(i, 5), (h), (f, 8)}
Output: 
5
No
Explanation: 
Inserting 2, 4, 3, and 5 
onto the stack. Returning top element 
which is 5. Finding 8 will give No, 
as 8 is not in the stack.
 

Example 2:

Input: 
Q = 4
Queries = {(i, 3), (i, 4), (r), (f, 3)}
Output: 
Yes
Explanation: 
Inserting 3 and 4 onto the 
stack. Finding 3 will give Yes as output 
because 3 is available in the stack.
 

Your Task:
Your task is to complete functions insert(), remove(), headOf_Stack() which takes a stack as input parameter, and find() which takes a stack and value as input parameter, to insert, remove returning top element, and finding the element in stack respectively.

 

Expected Time Complexity:
For find(): O(N),
For others: O(1).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ Number of queries ≤ 103
*/

// Code:
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++


// Helper class to implement functions
// insert : to insert element to stack
// remove : to pop element from stack
// headOf_Stack : to return top of stack
// find : to find the element in stack

void insert(stack<int> &s,int x)
{
    s.push(x);
}

void remove(stack<int> &s)
{
    
    s.pop();
}

void headOf_Stack(stack<int> &s)
{
    int x=s.top();
    cout<<x<<" "<<endl; 
}

bool find(stack<int> s, int val)
{
    bool exists=false;
    
    while(s.empty() == false) {
        if(s.top() == val) {
            exists = true;
            break;
        } 
        s.pop();
    }
    
    if(exists==true){
        return true;
    }
    else{
        return false;
    }
}

// { Driver Code Starts.

int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    stack<int> s;
	    int q;
	    cin>>q;
	    while(q--){
	        char ch;
	        cin>>ch;
	        
	        if(ch=='i')
	        {
	            int x;
	            cin>>x;
	            
	            insert(s,x);
	            
	        }
	        else if(ch=='r')
	        {
	            remove(s);
	        }
	        else if(ch=='h')
	        {
	            headOf_Stack(s);
	        }
	        else if(ch=='f')
	        {
	            int x;
	            cin>>x;
	            if(find(s,x))
	            cout << "Yes";
	            else cout << "No";
	            cout << endl;
	        }
	        
	    }
	}
	return 0;
}


  // } Driver Code Ends