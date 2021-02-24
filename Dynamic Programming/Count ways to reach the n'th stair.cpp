// Question:

/*
There are N stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does matter).

Example 1:

Input:
N = 4
Output: 5
Explanation:
You can reach 4th stair in 5 ways. 
Way 1: Climb 2 stairs at a time. 
Way 2: Climb 1 stair at a time.
Way 3: Climb 2 stairs, then 1 stair and then 1 stair.
Way 4: Climb 1 stair, then 2 stairs then 1 stair.
Way 5: Climb 1 stair, then 1 stair and then 2 stairs.
Example 2:

Input:
N = 10
Output: 89 
Explanation: 
There are 89 ways to reach the 10th stair.
Your Task:
Complete the function countWays() which takes the top stair number m as input parameters and returns the answer % 10^9+7.

Expected Time Complexity : O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
*/




// Code:

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int countWays(int);

int main()
{
    //taking total testcases
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
}
// } Driver Code Ends


// function to count ways to reach mth stair
int countWays1(int sum)
{   const int p = pow(10,9) + 7;
    int dp[sum+1];
    for(int i=0;i<=sum;i++) {
        if(i == 0) {
            dp[i] = 1;
        } else {
            int t1=0,t2=0;
            if(i-1>=0)
               t1 = dp[i-1]%p;
            if(i-2>=0) {
               t2 = dp[i-2]%p;
            }
            dp[i] = t1+t2;
        }
    }
    return dp[sum]%p;
}

int countWays(int m){
    
    return countWays1(m);
}