// Question:
/*
Given an array of distinct integers, find all the pairs having both negative and positive values of a number in the array.


Example 1:

Input:
N = 8
arr[] = {1,3,6,-2,-1,-3,2,7}
Output: -1 1 -3 3 -2 2
Explanation: 1, 3 and 2 are present 
pairwirse postive and negative. 6 and 
7 have no pair.
 

Example 2:

Input:
N = 3
arr[] = {3,2,1}
Output: 0
Explanation: No such pair exists so the 
output is 0.
 

Your Task:
You do not need to read input or print anything. Complete the function findPairs() which takes the array A[] and the size of the array, N, as input parameters and returns a list of integers denoting the pairs. The pair that appears first in A[] should appear first in the returning list and within the pair the negative integer should appear before positive integer. Return an empty integer list if no such pair exists. 

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 106
-106 <= arr[i] <= 106
*/


// Code:
// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
#include <math.h>
using namespace std;

vector<int> findPairs(int *, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector <int> res = findPairs(arr, n);
    	if(res.size()!=0)
    	{
    		for (int i : res) 
            	cout << i << " ";
        	cout << endl;	
    	}
    	else
    		cout<<0<<endl;
    }

    return 0;
}// } Driver Code Ends


// User function template for C++

vector <int> findPairs(int a[], int n) 
{    
    unordered_map <int,int> mp;
    vector<int> ab;
    for(int i=0;i<n;i++) {
        if(mp.count(-1*a[i])==1) {
            
            ab.push_back(-1*abs(a[i]));
            ab.push_back(abs(a[i]));
        }
        mp[a[i]]++;
    }
    return ab;
}