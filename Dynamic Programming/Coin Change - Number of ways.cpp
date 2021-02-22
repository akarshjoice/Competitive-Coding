// Question:

/*
You have an infinite supply of coins, each having some value. Find out the number of ways to use the coins to sum-up to a certain required value.

Example 1:

Input:
value = 4
numberOfCoins = 3
coins[] = {1,2,3}
Output: 4
Explanation: We need to make the change
for value = 4. The denominations are
{1,2,3} Change for 4 can be made:
1+1+1+1
1+1+2
1+3
2+2
So, as it is evident, we can do this in
4 ways.
Example 2:

Input:
value = 10
numberOfCoins = 4
coins[] = {2,5,3,6}
Output: 5
Your Task:
This is a function problem where you've to complete the funcion numberOfWays (). You are given an amount denoted by value. You are also given an array of coins. The array contains the denominations of the given coins. You need to return the number of ways you can make the change for value using the coins of given denominations. Also, keep in mind that you have an infinite supply of coins.
Note:  Try not to editing the part of the code provided to you in the function. Just complete the function as it has been described.

Expected Time Complexity: O(Number of Coins * Value).
Expected Auxiliary Space: O(Value).

Constraints:
1 <= value <= 103
1 <= numberOfCoins <= 103
1 <= coinsi <= 1000
*/


// Code:

// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//Complete this function
long long numberOfWays(int a[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=sum;j++) {
            if(i==0 && j!=0) {
                dp[i][j] = 0;
                continue;
            }
            if(j == 0) {
                dp[i][j] = 1;
            } else {
                if(j - a[i-1] >=0) {
                    dp[i][j] = dp[i][j - a[i-1]] +
                                    dp[i-1][j];
                } else {
                    dp[i][j] =  dp[i-1][j];
                }
            }
        }
    }
    return dp[n][sum];
    
}


// { Driver Code Starts.


int main() {
    
    //taking total count of testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking value
	    int value;
	    cin>>value;
	    
	    //taking number of coins
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    //inserting coins to the array
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    
	    //calling function numberOfWays
	    cout<<numberOfWays(coins,numberOfCoins,value)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends