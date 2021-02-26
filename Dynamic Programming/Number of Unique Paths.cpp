// Question:

/*
Given a A X B matrix with your initial position at the top-left cell, find the number of possible unique paths to reach the bottom-right cell of the matrix from the initial position.

Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].

Example 1:

Input:
A = 2, B = 2
Output: 2
Explanation: There are only two unique
paths to reach the end of the matrix of
size two from the starting cell of the
matrix.
Example 2:

Input:
A = 3, B = 4
Output: 10
Explanation: There are only 10 unique
paths to reach the end of the matrix of
size two from the starting cell of the
matrix.
Your Task:
Complete NumberOfPath() function which takes 2 arguments(A and B) and returns the number of unique paths from top-left to the bottom-right cell.

Expected Time Complexity: O(A*B).
Expected Auxiliary Space: O(A*B).

Constraints:
1 ≤ A ≤ 15
1 ≤ B ≤ 15
*/

// Code:

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int NumberOfPath( int, int);

// Position this line where user code will be pasted

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        
        //calling NumberOfPath() function
        cout << NumberOfPath(a,b) << endl;
    }
}

// } Driver Code Ends


//User function template in C++
int count1 = 0;
int NumberOfPath1(int a, int b) {
    
    if(a==1 && b==1) {
        count1++;
        return 1;
    } else if(a==1) {
        return NumberOfPath1(a,b-1);
    } else if(b==1) {
        return NumberOfPath1(a-1,b);
    }
    return NumberOfPath1(a-1,b) + NumberOfPath1(a,b-1);
}

int NumberOfPath(int a, int b) {
    count1 = 0;
    NumberOfPath1(a, b);
    return count1;
}