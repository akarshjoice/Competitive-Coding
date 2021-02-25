// Question:

/*
Given an integer. Find how many structurally unique binary search trees are there that stores the values from 1 to that integer (inclusive). 

Example 1:

Input:
N = 2
Output: 2
Explanation:for N = 2, there are 2 unique
BSTs
     1               2  
      \            /
       2         1
Example 2:

Input:
N = 3
Output: 5
Explanation: for N = 3, there are 5
possible BSTs
  1           3     3       2     1
    \        /     /      /  \     \
     3      2     1      1    3     2
    /      /       \                 \
   2      1         2                 3
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function numTrees() which takes the integer N as input and returns the total number of Binary Search Trees possible with keys [1.....N] inclusive. Since the answer can be very large, return the answer modulo 1000000007.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N).

Constraints:
1<=N<=1000
*/


// Code:

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#define mod (int)(1e9+7)
class Solution{
    public:
    // Functiuon to return number of trees
    
    // Return the total number of BSTs possible with keys [1....N] inclusive.
    int numTrees(int n) {
        long long int dp[n+1];
        for(int i=0;i<=n;i++) {
            long long int count =0;
            if(i == 0) {
                dp[i] = 1;
            } else if(i==1) {
                dp[i] = 1;
            } else {
                dp[i] = 0;
                for(int k=1;k<=i;k++) {
                    long long sub_res = (dp[k-1] * dp[i-k])%1000000007;
                    dp[i] = (dp[i] + sub_res)%1000000007; 
                }
            }
        }
        return dp[n];
        
    }
};

// { Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	  // } Driver Code Ends