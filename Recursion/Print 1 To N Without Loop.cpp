// Question:
/*
Print numbers from 1 to N without the help of loops.

Example 1:

Input:
N = 10
Output: 1 2 3 4 5 6 7 8 9 10

Example 2:

Input:
N = 5
Output: 1 2 3 4 5
 

Your Task:
This is a function problem. You only need to complete the function printNos() that takes N as parameter and prints number from 1 to N recursively. The driver code adds the newline automatically after the function call.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N) (Recursive).


Constraints:
1 <= N <= 990

*/

// Code:

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void printNos(int N);
/* Driver program to test printNos */
int main()
{
    int T;
    
    //taking testcases
    cin>>T;
    
    while(T--)
    {
        int N;
        
        //input N
        cin>>N;
        
        //calling printNos() function
        printNos(N);
        
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


//Complete this function
void printNos(int N)
{   if(N==0) return;
    
    
    printNos(N-1);
    cout<<N<<" ";
}