// Question:

/*
Find nCr for given n and r.

Example 1:

Input:
n = 3, r = 2
Output: 3
Example 2:

Input:
n = 4, r = 2
Output: 6
Your Task:
Complete the function nCrModp() which takes two integers n and r as input parameters and returns the nCr mod 109+7.
Note: nCr does not exist when r > n. Hence, return 0 in that case.

Expected Time Complexity : O(N*R)
Expected Auxiliary Space: O(N)

Constraints:
1<= n <= 103
1<= r <= 103
*/



// Code:

// { Driver Code Starts
// A Dynamic Programming based solution to compute nCr % p 
#include<bits/stdc++.h> 
using namespace std; 

const int p = 1e9+7;

int nCrModp(int, int);

// Driver program 
int main() 
{ 
  int t, n, r;
  
  //taking count of testcases
  cin >> t;
  
  while(t--){
      
      //taking n and r
      cin >> n >> r;
      
      //calling method nCrModp()
      cout << nCrModp(n, r) << endl;
  }
  
  return 0; 
}
// } Driver Code Ends



// Returns nCr % p 
int nCrModp(int n, int r) 
{ 
   int dp[n+1][r+1];
   for(int i=0;i<=n;i++) {
       for(int j=0;j<=r;j++) {
           if(j > i) {
               dp[i][j] = 0;
           } 
           else if(j==1) {
               dp[i][j] = i;
           } else {
               dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%1000000007; 
           }
        }
   }
   return dp[n][r];

} 