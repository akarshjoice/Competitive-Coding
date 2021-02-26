// Question:

/*
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Example 1:

Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6
Example 2:

Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence
5 7 9, with length 3
Your Task:
Complete the function longestSubsequence() which takes the input array and its size as input parameters and returns the length of the longest increasing subsequence.

Expected Time Complexity : O( N*log(N) )
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
0 ≤ A[i] ≤ 106
*/




// Code:

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];

        //calling method longestSubsequence()
        cout << longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends


// return length of longest strictly increasing subsequence
int binary_search(vector<int> a,int x) {
    int l=0;
    int u=a.size()-1;
    int m;
    while(l<u) {
        m=(l+u)/2;
        if(x>a[m]) {
            l=m+1;
        } else if(x<=a[m]) {
            u=m;
        }
    }
    return u;
}


int longestSubsequence(int n, int a[])
{   vector <int> dp;
    dp.push_back(a[0]);
    for(int i=1;i<n;i++) {
        if(a[i]>dp[dp.size()-1]) {
            dp.push_back(a[i]);
        } else {
            int j = binary_search(dp,a[i]);
            dp[j] = a[i];
        }
    }
    return dp.size();
}


/* Solution - 2
int longestSubsequence(int n, int a[])
{
   int dp[n];
   dp[0] = 1;
   for(int i=1;i<n;i++) {
       dp[i] = 1;
       for(int j=0;j<i;j++) {
           if(a[j]<a[i]) {
               dp[i] = max(dp[i],dp[j]+1);
           }
       }
   }
   int maxval = INT_MIN;
   for(int i=0;i<n;i++) {
       maxval=max(maxval,dp[i]);
   }
   return maxval;
}*/