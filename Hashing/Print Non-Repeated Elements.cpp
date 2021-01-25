// Question:
/*
Hashing is very useful to keep track of the frequency of the elements in a list.

You are given an array of integers. You need to print the non-repeated elements as they appear in the array.

Example 1:

Input:
n = 10
arr[] = {1,1,2,2,3,3,4,5,6,7}
Output: 4 5 6 7
Explanation: 4, 5, 6 and 7 are the only 
elements which is having only 1 
frequency and hence, Non-repeating.
Example 2:

Input:
n = 5
arr[] = {10,20,40,30,10}
Output: 20 40 30
Explanation: 20, 40, 30 are the only 
elements which is having only 1 
frequency and hence, Non-repeating.
Your Task:
You don't need to read input or print anything. You only need to complete the function printNonRepeated() that takes arr and n as parameters and return the array which has the distinct elements in same order as they appear in input array. The newline is appended automatically by the driver code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 103
0 <= arri <= 107
*/



// Code:
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> printNonRepeated(int arr[],int n);


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	    vector<int> v;
	    v = printNonRepeated(arr,n);
	    
	    for(int i=0;i<v.size();i++)  
	        cout<<v[i]<<" ";
	    
	    cout<<endl;
	    
	}
	return 0;
}

// } Driver Code Ends


// Function to print the non repeated elements in the array
// arr[]: input array
// n: size of array
vector<int> printNonRepeated(int arr[],int n)
{   
    vector<int> a;
    unordered_map <int,int> mp;
    for(int i=0;i<n;i++) {
        mp[arr[i]]++;
    }
    int count = 0;
    for(int i=0;i<n;i++) {
        if(mp[arr[i]] == 1) {
            a.push_back(arr[i]);
        }
    }
    return a;
}