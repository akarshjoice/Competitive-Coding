// Question:

/*
Given an integer S represented as a string, the task is to get the sum of all possible sub-strings of this string.
As the answer will be large, print it modulo 10^9+7.

Example 1:

Input:
S = 1234
Output: 1670
Explanation: Sum = 1 + 2 + 3 + 4 + 12 +
23 + 34 + 123 + 234 + 1234 = 1670
Example 2:

Input:
S = 421
Output: 491
Explanation: Sum = 4 + 2 + 1 + 42 + 21
Your Task:
You only need to complete the function sumSubstrings that takes S as an argument and returns the answer modulo 1000000007.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= |S| <= 104
*/

// Code:

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

long long sumSubstrings(string);

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        
        //calling sumSubstrings() function
        cout << sumSubstrings(s) << endl;
        
    }
    return 0;
}
// } Driver Code Ends


// function to find sum of all possible substrings of the given string
#include<string.h>


long long sumSubstrings(string s){
    
    int n = s.length();
    long long int dp[n];
    long long int sum = 0;
    dp[0] = s[0]-'0';
    sum = dp[0];
    for(int i=1;i<n;i++) {
        dp[i] = ((i+1)*(s[i]-'0') + 10*dp[i-1])%1000000007;
        sum= (sum + dp[i])%1000000007;
    }

    return sum;
}