//Question:

/*
Given a number N. The task is to find the length of the longest consecutive 1s in its binary representation.

Example 1:

Input: N = 14
Output: 3
Explanation: Binary representation of 14 is 
1110, in which 111 is the longest consecutive 
set bits of length is 3.
Example 2:

Input: N = 222
Output: 4
Explanation: Binary representation of 222 is 
11011110, in which 1111 is the longest 
consecutive set bits of length 4. 

Your Task: The task is to complete the function maxConsecutiveOnes() which returns the length of the longest consecutive 1s in the binary representation of given N.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
*/



//Code:

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

/*  Function to calculate the largest consecutive ones
*   x: given input to calculate the largest consecutive ones
*/
int maxConsecutiveOnes(int n)
{
 
    unsigned int pre = n - (n&(n-1));
    n = n&n-1;
    int max = 0;
    int count;
    if(n!=0)
        {count =1;
         max = 1;
        }
    
    int flag = 0;
    while(n) {
        
        unsigned int new1 = n - (n&(n-1)); 
        if(pre*2 == new1) {
            if(flag == 0) {
                flag = 1;
                
            }
            count++;
            if(count>max) {
                max = count;
            }
        pre = new1;
        n=n&(n-1);
        continue;
        }
        flag = 0;
        count = 1;
        
        pre = new1;
        n=n&(n-1);
    }
    
    return max;
    
    
}



// { Driver Code Starts.

// Driver Code
int main() {
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		
		//calling maxConsecutiveOnes() function
		cout<<maxConsecutiveOnes(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends