// Question:

/*
Kadane's algorithm comes into picture when we want to find the maximum possible sum in an array when summing the contiguous elements of the array.

You are given an array. Find the maximum possible sum of contiguous elements of the array ending at each position in the array. Also, return the overall maximum that we can achieve.

 

Example 1:

Input:
N = 6
arr[] = {5,2,-3,32,-5,65}
Output: 5 3 0 32 27 92
        92
Explanation: Maximum sum at each index is
5, 3, 0, 32, 27, 92. And, maximum sum for
contiguous array is 92.

Example 2:

Input:
N = 5
arr[] = {-9,-8,8,3,-4}
Output: -9 -8 8 11 7
         11

Your Task:
This is a function problem. You don't need to take any input. Just complete the function maximumSum() that takes the integer array and its size as inputs and prints the maximum contiguous subarray sum ending at each position in the array. Also, return the overall maximum.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <= sizeOfArray <= 103
-103 <= Ai <= 103
*/

// Code:

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

//Complete this function
long long maximumSum(int a[], int n)
{
   long long int maxending = a[0], maxval = a[0];
   cout<<maxending<<" ";
   for(int i =1;i<n;i++) {
       maxending = max(maxending + (long long)a[i], (long long) a[i]);
       maxval = max(maxval, maxending);
       cout<<maxending<<" ";
   }
   cout<<endl;
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
	    
	    //inserting elements to the array
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    //calling function maximumSum()
	    cout<<maximumSum(arr,sizeOfArray)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends