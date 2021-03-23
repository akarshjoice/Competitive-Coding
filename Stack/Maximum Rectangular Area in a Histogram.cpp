// Question:
/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation: 


Example 2:

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.
Your Task:
The task is to complete the function getMaxArea() which takes the array arr[] and its size N as inputs and finds the largest rectangular area possible and returns the answer.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 <= N <= 106
1 <= arr[i] <= 1012
*/

// Code:
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array

class Solution
{
    public:
    void mintoleft(long long arr[], int n, vector <long long> &a) {
        stack <int> st;
        a.push_back(-1);
        st.push(0);
        for(int i=1;i<n;i++) {
            while(st.empty() == false && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            long long value = (st.empty() == true)?-1:st.top();
            a.push_back(value);
            st.push(i);
        }
    }
    
    void mintoright(long long arr[], int n, vector <long long> &a) {
        stack <int> st;
        //a.insert(a.begin(),n);
        a.push_back(n);
        st.push(n-1);
        for(int i=n-2;i>=0;i--) {
            while(st.empty() == false && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            long long value = (st.empty() == true)?n:st.top();
            //a.insert(a.begin(), value);
            a.push_back(value);
            st.push(i);
        }
    }
    
    
    long long getMaxArea(long long arr[], int n){
    
        vector<long long> a,b;
        mintoleft(arr,n,a);
        mintoright(arr,n,b);
        reverse(b.begin(),b.end());
        long long maxval = -1;
        for(int i=0;i<n;i++) {
            long long count=1;
            count+=(i-a[i]-1);
            count+=(b[i]-i-1);
            count*=arr[i];
            maxval = max(maxval,count);
        }
        return maxval;
    
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends