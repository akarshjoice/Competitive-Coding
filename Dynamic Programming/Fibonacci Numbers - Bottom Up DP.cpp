// Question:

/*
One of the rudimentary problems to understand DP is finding the nth Fibonacci number. Here, we will solve the problem using a bottom-up approach.
You are given a number N. You need to find the Nth Fibonacci number. The first two number of the series are 1 and 1.

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
You don't need to take any input. You have to complete the function findNthFibonacci() which takes single argument(number N) and returns the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 92
*/


// Code:

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

long long findNthFibonacci(int number);

 // } Driver Code Ends
//User function Template for C++
// You need to complete this function

// Return the number-th Fibonacci 
long long findNthFibonacci(int n)
{   
    long long dp[n+1];
    for(long long i=0;i<=n;i++) {
        if(i == 0) 
            dp[i] = 0;
        else if(i == 1) 
            dp[i] = 1;
        else
            dp[i] = dp[i-1] + dp[i-2];
   
    }
    return dp[n];
}

// { Driver Code Starts.

int main()
 {
    //taking testcases
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        //taking nth fibonacci 
        //to be found
        int number;
        cin>>number;
        
        //calling function findNthFibonacci()
        //and passing number as parameter
        cout<<findNthFibonacci(number)<<endl;
    }
    
	return 0;
}
  // } Driver Code Ends