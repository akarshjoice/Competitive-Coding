// Question:

/*
You are given an array arr of size sizeOfArr. You need to find the maximum sum in the array provided that you cannot sum neighboring elements or adjacent elements.

Example 1:

Input:
sizeOfArr = 4
arr[] = {4,5,6,7,8}
Output: 18
Explanation:The given elements are 4 5 6 7 8
For 4, the maximum sum will be 4 as no
element other than 4 from index 0 to 0
For 5, the maximum sum will be 5 as we cannot
add 4 and 5(neighboring elements).
For 6, the maximum sum will be 10 as we can
add 6 and 4.
For 7, the maximum sum will be 12 as we can
add 7 and 5.
For 8, the maximum sum will be 18 as we can
add 4 and 6 and 8.
Example 2:

Input:
sizeOfArr = 5
arr[] = {-9,-8,8,3,-4}
Output: 8
Your Task:
This is a function problem. You only need to complete the function maximumSum() that takes array and sizeOfArray and returns the maximum sum of the array provided that you cannot sum neighboring elements.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= sizeOfArr <= 103
-103 <= arri <= 103
*/


// Code:

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

//Complete this function
typedef long long int ll;

ll FindMaxSum(int a[], ll n)
{   
    ll dp[n+1];
    for(ll i=0;i<=n;i++) {
        if(i==0) {
            dp[i] = 0;
        } else if(i-2>=0)
            dp[i] = max((ll)a[i-1] + dp[i-2],dp[i-1]);
        else {
            dp[i] = max((ll)a[i-1] ,dp[i-1]); 
        }        
    }
    return dp[n];

}


long long maximumSum(int a[], int n)
{  long long int maxval = INT_MIN;
   for(int i=0;i<n;i++) {
       if(a[i]>=0) {
          return FindMaxSum(a,n);
       }
       maxval = max(maxval,(ll)a[i]);
   }    
   return maxval;
}


// { Driver Code Starts.


int main() {
    
    //taking total testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking size of array
	    int sizeOfArray;
	    cin>>sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    //inserting elements in the array
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    //calling function maximumSum()
	    cout<<maximumSum(arr,sizeOfArray)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends