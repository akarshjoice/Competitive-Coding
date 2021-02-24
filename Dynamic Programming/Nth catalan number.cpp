// Question:

/*
Given a number N. The task is to find the Nth catalan number.
The first few Catalan numbers for N = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
Note: Positions start from 0 as shown above.

Example 1:

Input:
N = 5
Output: 42
Example 2:

Input:
N = 4
Output: 14
Your Task:
Complete findCatalan() function that takes n as an argument and returns the Nth Catalan number. The output is printed by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/

// Code:

// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;

cpp_int findCatalan(int);

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    
	    //calling function findCatalan function
	    cout<< findCatalan(n) <<"\n";    
	}
	return 0;
}// } Driver Code Ends


//User function template for C++

// n : given integer value
cpp_int findCatalan(int n) {
    
    cpp_int dp[n+1];
    
    for(int i=0;i<=n;i++) {
        cpp_int count = 0;
        if(i==0) {
            dp[i] = 1;
        }
        else if(i==1) {
            dp[i] = 1;
        }else {
            for(int k=1;k<=i;k++) {
                count+= dp[k-1]*dp[i-k];
            }
            dp[i] = count;
        }
    }
    return dp[n];
    
}