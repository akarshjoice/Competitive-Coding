// Question:

/*
Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find the number of distinct combinations to reach the given score.

Example 1:

Input:
n = 8
Output: 1
Explanation:when n = 8,{3,5} and {5,3}
are the two possible permutations but
these represent the same cobmination.
Hence output is 1.
Example 2:

Input:
n = 20
Output: 4
Explanation:When n = 20, {10,10},
{5,5,5,5},{10,5,5} and {3,3,3,3,3,5}
are different possible permutations.
Hence output will be 4.
Your Task:
Complete count() function which takes N as an argument and returns the number of ways/combinations to reach the given score.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ n ≤ 1000
*/


// Code:

// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll count(ll n);

int main()
{
    //taking total testcases
	int t;
	cin>>t;
	
	while(t--)
	{
	    //taking the score
		ll n;
		cin>>n;
		
		//calling function count()
		cout << count(n) << "\n";
	}
	return 0;
}// } Driver Code Ends


//User function tempate for C++

// n :  given score 

ll count1(ll a[],ll n,ll sum) {
    ll dp[n+1][sum+1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=sum;j++) {
            ll c = 0;
            if(j == 0) {
                dp[i][j] = 1;
            } else {
                for(ll k=i;k>0;k--) {
                    if(j-a[k-1]>=0)
                        c+=dp[k][j-a[k-1]];
                }
                dp[i][j] = c;
            }
            
        }
    }
    return dp[n][sum];
    
}


ll count(ll n) {
    
    ll a[3];
    a[0] = 3;
    a[1] = 5;
    a[2] = 10;
    return count1(a,3,n);
}