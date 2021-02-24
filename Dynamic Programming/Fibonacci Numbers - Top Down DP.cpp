// Question:

/*
One of the rudimentary problems to understand DP is finding the nth Fibonacci number. Here, we will solve the problem using the top-down approach.

You are given a number N. You need to find Nth Fibonacci number. The first two term of the series are 1 and 1.

Example 1:

Input:
N = 5
Output: 5
Example 2:

Input:
N = 7
Output: 13
Explanation: Some of the numbers of the
Fibonacci numbers are 1, 1, 2, 3, 5, 8,13
..... (N stars from 1).
Your Task:
You don't need to take any input. You have to complete the function findNthFibonacci() which takes 2 arguments(number N and dp array to store the answer) and returns the answer.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Note: This space is used by dp array.

Constraints:
1 <= N <= 92
*/



// Code:

// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
#include <fstream>
using namespace std;



 // } Driver Code Ends
//User function Template for C++

//Complete this function
long long findNthFibonacci(int n, long long int dp[])
{
   if(dp[n] == 0) {
        if(n == 0) 
            dp[n] = 0;
        else if(n == 1) 
            dp[n] = 1;
        else
            dp[n] = findNthFibonacci(n-1, dp) + findNthFibonacci(n-2, dp);
   }
   return dp[n];
}


// { Driver Code Starts.
long long findNthFibonacci(int number, long long int dp[]);

int main()
 {
    //initializing base value
    long long dp[100]={0};
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    
    //taking total testcases
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        //taking nth number 
        int number;
        cin>>number;
        
        //calling findNthFibonacci() function
        cout<<findNthFibonacci(number, dp)<<endl;
    }
    
	return 0;
}
  // } Driver Code Ends