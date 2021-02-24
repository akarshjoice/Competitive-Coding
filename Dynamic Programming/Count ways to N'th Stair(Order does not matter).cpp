// Question:

/*
There are N stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).
Note: Order does not matter means for n=4 {1 2 1},{2 1 1},{1 1 2} are considered same.

Example 1:

Input:
N = 4
Output: 3
Explanation: You can reach 4th stair in
3 ways.
3 possible ways are:
1, 1, 1
1, 1, 2
2, 2
Example 2:

Input:
N = 5
Output: 3
Explanation:
You may reach the 5th stair in 3 ways.
The 3 possible ways are:
1, 1, 1, 1, 1
1, 1, 1, 2
1, 2, 2
Your Task:
Your task is to complete the function countWays() which takes single argument(N) and returns the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 106
*/


// Code:

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

long long mod =1000000007;

long long countWays(int);

int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        
        
        cout<<countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}// } Driver Code Ends

long long countWays1(int n, int sum) {
    long long dp[n+1][sum+1];
    for(long long i=0;i<=n;i++) {
        for(long long j=0;j<=sum;j++) {
            long long count = 0;
            if(j == 0) {
                dp[i][j] = 1;
            } else {
                for(long long k=i;k>=1;k--) {
                    if(j-k >=0)
                        count+= dp[k][j-k];
                }
                dp[i][j] = count;
            }
        }
    }
    return dp[n][sum];
       
}


// function to count ways to reach mth stair
long long countWays(int m){
    
    return countWays1(2,m);
}