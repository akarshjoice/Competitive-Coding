// Question:

/*
Given an array arr[] of N positive integers and a number K. The task is to find the kth smallest element in the array.

Example 1:

Input: 
N = 5, K = 3
arr[] = {3,5,4,2,9}

Output: 
4

Explanation: 
Third smallest element in the array is 4.
Example 2:

Input:
N = 5, k = 5
arr[] = {4,3,7,6,5}

Output: 
7

Explanation: 
Fifth smallest element in the array is 7.

Your Task:
You  don't need to read inputs or print anything. Complete the method kthSmallest() which takes array arr[], size of the array n and value k as input parameters and returns kth smallest element.

Constraints:
1 <= N <= 106
1 <= arr[i] <= 106
1 <= K <= N
Array do not contains duplicates.

Expected Time Complexity: O(NlogK)
Expected Auxilliary Space: O(K)
*/

// Code:
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
        //Function to find the kth smallest element in the array.
        int kthSmallest(int a[], int n, int k){
            
            priority_queue<int,vector<int>,greater<int>> pq;
            for(int i=0;i<n;i++) {
                pq.push(a[i]);
            }
            for(int i=1;i<k;i++) {
                pq.pop();
            }
            return pq.top();
    }
};

// { Driver Code Starts.
int main(){
	
	int t;
	cin >> t;
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    int arr[n];
	    
	    for(int i = 0; i<n; ++i)
	        cin>>arr[i];
	        
	    Solution ob;
	    cout << ob.kthSmallest(arr, n, k) << endl;
	    
	}
	return 0;
}  // } Driver Code Ends