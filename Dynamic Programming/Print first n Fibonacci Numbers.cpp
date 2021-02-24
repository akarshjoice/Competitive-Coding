// Question:

/*
Given a number N, find the first N Fibonacci numbers. The first two number of the series are 1 and 1.

Example 1:

Input:
N = 5
Output: 1 1 2 3 5
Example 2:

Input:
N = 7
Output: 1 1 2 3 5 8 13
Your Task:
Your task is to complete printFibb() which takes single argument N and returns a list of first N Fibonacci numbers.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Note: This space is used to store and return the answer for printing purpose.

Constraints:
1<= N <=84
*/



// Code:

// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;
vector<long long> printFibb(int);



int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        
        //calling function printFibb()
        vector<long long> ans = printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends


//User function template for C++

// n : given integer value
// print the nth fibb number in the function 
vector<long long> printFibb(int n) {
    vector <long long> dp(n+1);
    for(long long i=0;i<=n;i++) {
        if(i == 0) 
            dp[i] = 0;
        else if(i == 1) 
            dp[i] = 1;
        else
            dp[i] = dp[i-1] + dp[i-2];
   
    }
    
    for(int i=0;i<n;i++) {
        dp[i] = dp[i+1];
    }
    dp.resize(n);
    return dp;
    
}