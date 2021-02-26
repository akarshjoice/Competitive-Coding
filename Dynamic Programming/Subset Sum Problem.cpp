// Question:

/*
Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Example 1:

Input:
N = 4
arr[] = {1,5,11,5}
Output: YES
Explanation: There exists two subsets
such that {1, 5, 5} and {11}.
Example 2:

Input:
N = 3
arr[] = {1,3,5}
Output: NO
Your Task:
Your task is to complete the findPartition() function which takes an array a[] and N as input parameter and return true if the given set can be partitioned into two subsets such that the sum of elements in both subsets is equal, else return false.
Note: The output will be YES or NO depending upon the value returned by your code. The printing is done by the driver's code.

Expected Time Complexity: O(N*S).
Expected Auxiliary Space: O(S) where S is the sum of the given Array.

Constraints:
1 <= N <= 100
0 <= arr[i] <= 1000
*/




// Code:

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>

using namespace std;

bool findPartition(int *, int);

// Position this line where user code will be pasted.

int main() {
    
    //taking total testcases
    int tc;
    cin >> tc;
    while (tc--) {
        
        //taking size of array
        int n, i;
        cin >> n;
        int a[n];
        
        //inserting elements in the array
        for (i = 0; i < n; i++) cin >> a[i];

        //calling findPartition() function and
        //printing "YES", if it returns true
        //else "NO"
        if (findPartition(a, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
// } Driver Code Ends


// User function template in C++

// a : given array
// n : size of the array
int findPartition1(int a[], int n, int sum) {
    int row1[sum+1];
    int row2[sum+1];
    int flag = 1;
    for(int i=0;i<=n;i++) {
        flag = (flag == 1)?0:1; 
        for(int j=0;j<=sum;j++) {
            if(j==0) {
                 if(flag == 0) {
                    row1[j] = 1;
                 } else {
                     row2[j] = 1;
                 }
               
            } else if(i==0) {
                if(flag == 0) {
                    row1[j] = 0;
                 } else {
                     row2[j] = 0;
                 }
            }
            else {
                if(flag == 0) {
                    if(j-a[i-1]>=0) {
                        row1[j] = row2[j] || row2[j-a[i-1]]; 
                    } else {
                        row1[j] = row2[j];
                    }
                } else {
                    if(j-a[i-1]>=0) {
                        row2[j] = row1[j] || row1[j-a[i-1]]; 
                    } else {
                        row2[j] = row1[j];
                    }
                }
            }
        }
    }
    if(flag == 0) {
        return row1[sum];
    } else {
        return row2[sum];
    }
}

bool findPartition(int a[], int n) {
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += a[i];
    }
    if(sum%2 != 0) {
        return false;
    }
    bool p=(findPartition1(a, n, (sum/2))==1)?true:false;
    return p;
}