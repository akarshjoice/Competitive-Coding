// Question:

/*
Given a positive integer N, the task is to find the number of different ways in which N can be written as a sum of two or more positive integers.

Example 1:

Input:
N = 5
Output: 6
Explanation: 
1+1+1+1+1
1+1+1+2
1+1+3
1+4
2+1+2
2+3
So, a total of 6 ways.
Example 2:

Input:
N = 3
Output: 2
Your Task:
Your task is to complete the function countWays() which takes 1 argument(N) and returns the answer%(10^9 + 7).

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 103
*/


// Code:

// { Driver Code Starts
#include<bits/stdc++.h>


using namespace std;

int countWays(int);

// Driver program
int main()
{
    //taking number of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin>>n;
        cout<<countWays(n)<<endl;
    }
    return 0;
}// } Driver Code Ends


// function to count number of ways in which n can
// be written as sum of two or more than two integers
int countWays1(vector<int> a, int n, int sum) {
    const int p = (pow(10,9) + 7);
    int dp[n+1][sum+1]; 
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=sum;j++) {
           if(j == 0) {
             dp[i][j] = 1;
            }
           else if(i==0) {
                dp[i][j] = 0;
            }
           else {
                if(j-a[i-1] >= 0) {
                    dp[i][j] = (dp[i-1][j] + dp[i][j-a[i-1]])%p;
                } else {
                    dp[i][j] = dp[i-1][j];
                } 
           }
        }
    }
    return dp[n][sum];
        
}


int countWays(int n)
{  
    vector <int> a;
    for(int i=1;i<n;i++) {
        a.push_back(i);
    }
    return countWays1(a,n-1,n);
}