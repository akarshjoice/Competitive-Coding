// Question:

/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

Example 1:

Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110
Example 2:

Input:
n = 3
a[] = {1,2,3}
Output: 4
Explanation: 1+3=4
Your Task:
Complete the function FindMaxSum() which takes an array arr[] and n as input which returns the maximum money he can get following the rules
 

Expected Time Complexity: O(N).
Expected Space Complexity: O(N).

Constraints:
1 <= n <= 104
1 <= a[i] <= 104
*/


// Code:

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


 // } Driver Code Ends
// Function to return maximum of sum without adjacent elements
ll FindMaxSum(ll a[], ll n)
{   
    ll dp[n+1];
    for(ll i=0;i<=n;i++) {
        if(i==0) {
            dp[i] = 0;
        } else if(i-2>=0)
            dp[i] = max(a[i-1] + dp[i-2],dp[i-1]);
        else {
            dp[i] = max(a[i-1] ,dp[i-1]); 
        }        
    }
    return dp[n];

}


// { Driver Code Starts.

int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		ll n;
		cin>>n;
		ll a[n];
		
		//inserting money of each house in the array
		for(ll i=0;i<n;++i)
			cin>>a[i];
			
		//calling function FindMaxSum()
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends