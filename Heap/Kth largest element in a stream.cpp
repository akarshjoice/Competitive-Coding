// Question:
/*
Given an input stream of n integers, find the kth largest element for each element in the stream.

Example 1:

Input:
k = 4, n = 6
arr[] = {1,2,3,4,5,6}
Output: -1 -1 -1 1 2 3
Explanation: k = 4
For 1, the 4th largest element doesn't
exist so we print -1.
For 2, the 4th largest element doesn't
exist so we print -1.
For 3, the 4th largest element doesn't
exist so we print -1.
For 4, the 4th largest element is 1
{1, 2, 3, 4}
For 5, the 4th largest element is 2
{2, 3, 4 ,5}
For 6, the 4th largest element is 3
{3, 4, 5, 6}

Example 2:

Input:
k = 1, n = 2
arr[] = {3,4}
Output: 3 4 
Your Task:
You are required to complete the method kthLargest() which takes 3 arguments and prints kth largest element -1.

Constraints:
1 <= n <= 106
1 <= K <= n
1 <= stream[i] <= 105

Expected Time Complexity : O(NlogK)
Expected Auxilliary Space : O(K)
*/

// Code:
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
        void kthLargest(int a[], int n, int k)
    {
    	priority_queue <int,vector<int>,greater<int>> pq;
    	int j;
    	for(int i=0;i<k-1;i++) {
    	    cout<<-1<<" ";
    	}
    	
    	for(j=0;j<k;j++) {
    	    pq.push(a[j]);
    	}
    	cout<<pq.top()<<" ";
    	for(int i=k;i<n;i++) {
    	    if(a[i]>pq.top()) {
    	        pq.pop();
    	        pq.push(a[i]);
    	        cout<<pq.top()<<" ";
    	    } else {
    	        cout<<pq.top()<<" ";
    	    }
    	}
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k, n;
		cin>>k>>n;
	    
	    int arr[n];
	    for(int i = 0; i<n ; ++i)
	        cin>>arr[i];
        Solution ob;
	    ob.kthLargest(arr, n, k);
	    cout<<endl;
	    
	    
	}
	return 0;
}
  // } Driver Code Ends