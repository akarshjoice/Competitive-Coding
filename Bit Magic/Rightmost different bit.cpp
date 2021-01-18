//Question:

/*
Given two numbers M and N. The task is to find the position of the rightmost different bit in the binary representation of numbers.

Example 1: 

Input: M = 11, N = 9
Output: 2
Explanation: Binary representation of the given 
numbers are: 1011 and 1001, 
2nd bit from right is different.
Example 2:

Input: M = 52, N = 4
Output: 5
Explanation: Binary representation of the given 
numbers are: 110100â€¬ and 0100, 
5th-bit from right is different.
User Task:
The task is to complete the function posOfRightMostDiffBit() which takes two arguments m and n and returns the position of first different bits in m and n. If both m and n are the same then return -1 in this case.

Expected Time Complexity: O(max(log m, log n)).
Expected Auxiliary Space: O(1).

Constraints:
1 <= M <= 103
1 <= N <= 103
*/


//Code:

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends


//User function Template for C++

/*  Function to find the first position with different bits
*   This function returns the position with different bit
*/
int posOfRightMostDiffBit(int m, int n)
{
    
    int res = m ^ n;
    if(res==0) {
        return 0;
    }
    int r = res - (res&(res-1));
    int p = log(r)/log(2);
    return p+1;
    
    
}

// { Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         cout << posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
}   // } Driver Code Ends