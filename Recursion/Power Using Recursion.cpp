// Question:
/*
You are given two numbers n and p. You need to find np.

Example 1:

Input:
n = 9 p = 9 
Output: 387420489â€¬
Explanation: 387420489 is the value 
obtained when 9 is raised to the 
power of 9.

Example 2:

Input:
n = 2 p = 9
Output: 512
Explanation: 512 is the value 
obtained when 2 is raised to 
the power of 9.  
Your Task:
You don't need to read input or print anything. You only need to complete the function RecursivePower() that takes n and p as parameters and returns np.

Expected Time Complexity: O(p).
Expected Auxiliary Space: O(p).

Constraints:
1 <= n <= 9
0 <=  p <= 9
*/


// Code:
// { Driver Code Starts
//Initial Template for C++


#include <iostream>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//Complete this function
int RecursivePower(int n,int p)
{
    if(p==0) {
        return 1;
    } else {
        return n * RecursivePower(n,p-1);
    } 
}


// { Driver Code Starts.


int main() {
	int T;
	cin>>T;//testcases
	while(T--)
	{
	    int n,p;
	    
	    //taking n and p as inputs
	    cin>>n>>p;
	    
	    //calling RecursivePower() function
	    cout<<RecursivePower(n,p)<<endl;
	}
	return 0;
}  // } Driver Code Ends