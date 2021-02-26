// Question:

/*
Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

Example 1:

Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.
Example 2:

Input:
N = 5
x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and
the cut lengths are 5, 3 and 2. We can
make two segments of lengths 3 and 2.
Your Task:
You only need to complete the function maximizeTheCuts() that takes n, x, y, z as parameters and returns max number cuts.

Expected Time Complexity : O(N)
Expected Auxiliary Space: O(N)

Constraints
1 <= N, x, y, z <= 104
*/



// Code:

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        
        //calling function maximizeTheCuts()
        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}// } Driver Code Ends


//Complete this function
int maximizeTheCuts(int n, int x, int y, int z)
{   
    int dp[n+1];
    for(int i=0;i<=n;i++) {
        if(i==0) {
            dp[i] = 0;
        } else { 
            int maxval = INT_MIN;
            if(i-x>=0)
                maxval = max(maxval,dp[i-x]);
            if(i-y>=0)
                maxval = max(maxval,dp[i-y]);
            if(i-z>=0)    
                maxval = max(maxval,dp[i-z]);
            if(maxval != INT_MIN) {
                dp[i] = 1+maxval;
            }
            else{
                dp[i] = maxval;
            } 
        }
    }
    if(dp[n] == INT_MIN) {
        return 0;
    }
    return dp[n];    

}