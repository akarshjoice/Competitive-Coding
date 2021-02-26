// Question:

/*
You are given array A of size n. You need to find the maximum-sum sub-array with the condition that you are allowed to skip at most one element.

Example 1:

Input:
n = 5
A[] = {1,2,3,-4,5}
Output: 11
Explanation: We can get maximum sum
subarray by skipping -4.
Example 2:

Input:
n = 8
A[] = {-2,-3,4,-1,-2,1,5,-3}
Output: 9
Explanation: We can get maximum sum
subarray by skipping -2 as [4,-1,1,5]
sums to 9, which is the maximum
achievable sum.
Your Task:

Your task is to complete the function maxSumSubarray that take array and size as parameters and returns the maximum sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= n <= 100
-103 <= Ai<= 103
*/


// Code:

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int maxSumSubarray(int [], int );

int main() {
	// your code goes here
	
	//taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking total elements
		int n;
		cin>>n;
		int a[n];
		
		//inserting elements in the array
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		
		//calling method maxSumSubarray()
		cout<<maxSumSubarray(a,n)<<endl;
	}
}

// } Driver Code Ends


/*You are required to complete below method */
int maxSumSubarray(int a[], int n)
{
    
   int l[n],r[n];
   int maxending=a[0],maxval = a[0];
   l[0] = a[0];
   for(int i=1;i<n;i++) {
       maxending = max(maxending + a[i], a[i]);
       l[i] = maxending;
       maxval = max(maxval,maxending);
   }
   maxending = a[n-1];
   r[n-1] = a[n-1];
   for(int i=n-2;i>=0;i--) {
       maxending = max(maxending + a[i], a[i]);
       r[i] = maxending;
   }
   int maxval1;
   for(int i=0;i<n;i++) {
       if(i==0) {
           maxval1 = r[i+1];
       } else if(i == n-1) {
           maxval1 = max(maxval1, l[i-1]); 
       } else {
           maxval1 = max(maxval1,l[i-1]+r[i+1]);
       }
      
   }
   return max(maxval1,maxval);
}