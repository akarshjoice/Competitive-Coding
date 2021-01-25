// Question:
/*
You are given an array of distinct integers and a sum. Check if there's a pair with the given sum in the array.

Example 1:

Input:
N = 10
arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} 
sum = 14
Output: 
1

Explanation: 
arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} 
and sum = 14.  There is a pair {4, 10} 
with sum 14.
Example 2:

Input:
N = 2
arr[] = {2, 5}
sum = 10
Output:
0

Explanation: 
arr[]  = {2, 5} and sum = 10. 
There is no pair with sum 10.
Your Task:
You don't need to read input or print anything. Your task is to complete the provided function sumExists () which take the array arr[], its size N, and an integer sum as inputs and returns 1 if there exists a pair with the given sum in the array, else, it returns 0.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 1000
1 <= arri <= 106
1 <= sum <= 1000
*/



// Code:
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int sumExists(int arr[], int sizeOfArray, int sum);

 // } Driver Code Ends


//User function Template for C++


//You need to complete this function, Geeks
int sumExists(int a[], int N, int sum)
{
   unordered_set<int> st;
   for(int i=0;i<N;i++) {
       if(st.count(sum-a[i])==1) {
           return 1;
       }
       st.insert(a[i]);
   }
   return 0;
}

// { Driver Code Starts.

int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        cin>>sizeOfArray;
        
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];
        int sum;
        cin>>sum;
        
        cout<<sumExists(arr,sizeOfArray,sum)<<endl;
        
        
    }
    
    
    
	return 0;
}
  // } Driver Code Ends