//Question:

/*
Given a number N. The task is to check whether it is sparse or not. A number is said to be a sparse number if no two or more consecutive bits are set in the binary representation.

Example 1:

Input: N = 2
Output: true
Explanation: Binary Representation of 2 is 10, 
which is not having consecutive set bits. 
So, it is sparse number.
Example 2:

Input: N = 3
Output: false
Explanation: Binary Representation of 3 is 11, 
which is having consecutive set bits in it. 
So, it is not a sparse number.

Your Task: The task is to complete the function checkSparse() that takes n as a parameter and returns true if the number is sparse else returns false.


Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
*/





//Code:
// { Driver Code Starts
//Initial Template for C++

// C++ program to check if n is sparse or not
#include<iostream>
using namespace std;

 // } Driver Code Ends


//User function Template for C++

// function to check if the number is sparse
// n : is the number to check if it is sparse
bool isSparse(int n){
    
    
    unsigned int pre = n - (n&(n-1));
    n = n&n-1;
    while(n) {
        
        unsigned int new1 = n - (n&(n-1)); 
        if(pre*2 == new1) {
            return false;
        }
        pre = new1;
        n=n&(n-1);
    }
    
    return true;
    
}


// { Driver Code Starts.

// Driver Code
int main()
{
    int t,n;
    
    //testcases
    cin>>t;
    while(t--)
    {
        //initializing n
        cin>>n;
        
        //printing 1 if isSparse() returns true
        //else 0
        if(isSparse(n)){
            cout << "1" << endl;
        }
        else cout << "0" << endl;
        
    }
    return 0;
}
  // } Driver Code Ends