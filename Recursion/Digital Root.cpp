// Question:
/*
You are given a number n. You need to find the digital root of n. DigitalRoot of a number is the recursive sum of its digits until we get a single digit number.

Example 1:

Input:
n = 1
Output:  1
Explanation: Digital root of 1 is 1
Example 2:

Input:
n = 99999
Output: 9
Explanation: Sum of digits of 99999 is 45
which is not a single digit number, hence
sum of digit of 45 is 9 which is a single
digit number.
Your Task:
You don't need to read input or print anything. Your task is to complete the function digitalRoot that takes n as parameter and returns the digital root of n. 

Expected Time Complexity: O((Num of Digits)2).
Expected Auxiliary Space: O(Num of Digits).

Constraints:
1 <= n <= 107
*/




// Code:
// { Driver Code Starts
//Initial Template for C++


#include <iostream>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//Complete this function
int sumOfDigits(int n)
{   if(n==0) {
       return 0;  
    }
    
    return n%10 + sumOfDigits(n/10);
}

int digitalRoot(int n)
{
    while(!(n>=0 && n<=9)) {
        n=sumOfDigits(n);
    }
    return n;
    
}

// { Driver Code Starts.


int main() {
	int T;
	cin>>T;//taking testcases
	while(T--)
	{
	    int n;
	    cin>>n;//taking number n
	    
	    //calling digitalRoot() function
	    cout<<digitalRoot(n)<<endl;
	    
	    
	}
	return 0;
}  // } Driver Code Ends