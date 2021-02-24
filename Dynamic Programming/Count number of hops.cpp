// Question:

/*
A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top. As the answer will be large find the answer modulo 1000000007.

Example 1:

Input:
N = 1
Output: 1
Example 2:

Input:
N = 4
Output: 7
Explanation:Below are the 7 ways to reach
4
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step
Your Task:
Your task is to complete the function countWays() which takes 1 argument(N) and returns the answer%(10^9 + 7).

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 105
*/

// Code:

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 
long long countWays(int);
 
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		
		//calling function countWays()
		cout << countWays(n) << endl;
	}
    
    return 0;
    
}
// } Driver Code Ends


long long countWays1(int sum)
{   const long long p = pow(10,9) + 7;
    long long dp[sum+1];
    for(long long i=0;i<=sum;i++) {
        if(i == 0) {
            dp[i] = 1;
        } else {
            long long t1=0,t2=0,t3=0;
            if(i-1>=0)
               t1 = dp[i-1]%p;
            if(i-2>=0) {
               t2 = dp[i-2]%p;
            }
            if(i-3>=0) {
               t3 = dp[i-3]%p;
            }
            dp[i] = t1+t2+t3;
        }
    }
    return dp[sum]%p;
}


// function to count number of ways to reach top of the stair
long long countWays(int n){
    
    return countWays1(n);
    
}