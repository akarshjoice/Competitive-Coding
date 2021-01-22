// Question:
/*
Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contiguous subarray sum.


Example 1:

Input:
N = 7
arr[] = {8,-8,9,-9,10,-11,12}
Output:
22
Explanation:
Starting from the last element
of the array, i.e, 12, and 
moving in a circular fashion, we 
have max subarray as 12, 8, -8, 9, 
-9, 10, which gives maximum sum 
as 22.
Example 2:

Input:
N = 8
arr[] = {10,-3,-4,7,6,5,-4,-1}
Output:
23
Explanation: Sum of the circular 
subarray with maximum sum is 23

Your Task:
The task is to complete the function circularSubarraySum() which returns a sum of the circular subarray with maximum sum.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).


Constraints:
1 <= N <= 10^6
-10^6 <= Arr[i] <= 10^6
*/

// Code:

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find circular subarray with maximum sum
// arr: input array
// num: size of array
int Kadans(int a[], int n){
    
    int maxending = a[0];
    int maxval=a[0];
    for(int i=1;i<n;i++) {
        maxending = max(maxending+a[i],a[i]);
        maxval = max(maxval,maxending);
    }
    return maxval;
    
}


int circularSubarraySum(int a[], int n){
    
    if(n == 1) {
        return a[0];
    }
    
    int nq = Kadans(a,n);
    if(nq<0) {
        return nq;
    } 
    
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum+=a[i];
        a[i]=-1*a[i];
    }
    int p = Kadans(a,n);
    return max(nq,(p+sum));
    
    
    
    
}

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	    
	    //calling function
	    cout << circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends