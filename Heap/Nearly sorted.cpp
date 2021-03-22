// Question:
/*
Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.

Example 1:

Input:
n = 7, k = 3
arr[] = {6,5,3,2,8,10,9}
Output: 2 3 5 6 8 9 10
Explanation: The sorted array will be
2 3 5 6 8 9 10
Example 2:

Input:
n = 5, k = 2
arr[] = {4,3,1,2,5}
Output: 1 2 3 4 5 
Note: DO NOT use STL sort() function for this question.

Your Task:
You are required to complete the method nearlySorted() which takes 3 arguments and returns the sorted array.

Expected Time Complexity : O(nlogk)
Expected Auxilliary Space : O(n)

Constraints:
1 <= n <= 106
1 <= k <= n
1 <= arri <= 107
*/

// Code:

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
        vector <int> nearlySorted(int a[], int num, int k){
            priority_queue<int,vector<int>,greater<int>> pq;
            
            for(int i=0;i<=k && i<num;i++) {
                
                pq.push(a[i]);
            }
            
            vector<int> b;
            for(int i=k+1;i<num;i++) {
                b.push_back(pq.top());
                pq.pop();
                pq.push(a[i]);
            }
            
            while(pq.empty() == false) {
                b.push_back(pq.top());
                pq.pop();
            }
            return b;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends