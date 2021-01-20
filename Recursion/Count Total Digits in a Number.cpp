//Question:
/*
You are given a number n. You need to find the count of digits in n.

Example 1:

Input:
n = 1
Output: 1
Explanation: Number of digit in 1 is 1.
Example 2:

Input:
n  = 99999
Output: 5
Explanation:Number of digit in 99999 is 5
Your Task:
You don't need to read input or print anything. Your task is to complete the function countDigits() that takes n as parameter and returns the count of digits in n.

Expected Time Complexity: O(Logn).
Expected Auxiliary Space: O(Logn).

Constraints:
0 <= n <= 107
*/


// Code:
// { Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//Complete this function
int countDigits1(int n)
{
   if(n == 0) {
       return 0;
   }
   return 1 + countDigits1(n/10);
   
}

int countDigits(int n) {
    if(n == 0) {
        return 1;
    } else {
        return countDigits1(n);
    }
}

// { Driver Code Starts.

int main() {
	int T;
	
	//taking testcases
	cin>>T;
	while(T--)
	{
	    int n;
	    
	    //taking number n
	    cin>>n;
	    
	    //calling countDigits
	    cout<<countDigits(n)<<endl;
	    
	    
	}
	return 0;
}


  // } Driver Code Ends