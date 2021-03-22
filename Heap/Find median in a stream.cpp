// Question:

/*
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Example 1:

Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5) 
15 goes to stream --> median 10 (5,15) 
1 goes to stream --> median 5 (5,15,1) 
3 goes to stream --> median 4 (5,15,1 3) 
 

Example 2:

Input:
N = 3
X[] = 5,10,15
Output:
5
7.5
10
Explanation:Flow in stream : 5, 10, 15
5 goes to stream --> median 5 (5) 
10 goes to stream --> median 7.5 (5,10) 
15 goes to stream --> median 10 (5,10,15) 
Your Task:
You are required to complete 3 methods insertHeap() which takes 1 argument, balanceHeaps() and getMedian() and returns the current median.
Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)
 
Constraints:
1 <= N <= 106
1 <= x <= 106
*/

// Code:
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
     priority_queue <int> maxh;
     priority_queue <int,vector<int>,greater<int>> minh;
    // Function to insert heap
    void insertHeap(int &x)
    {
       
        if(maxh.size() == 0) {
            maxh.push(x);
            return;
        }
        
        if(minh.size() < maxh.size()) {
            if(x>maxh.top()) {
                minh.push(x);
            } else {
                int tmp = maxh.top();
                maxh.pop();
                maxh.push(x);
                minh.push(tmp);
            }
        }
        else {
            if(x<minh.top()) {
                maxh.push(x);
            } else {
                int tmp = minh.top();
                minh.pop();
                minh.push(x);
                maxh.push(tmp);
            }
        }
        
        
    }
    
    // Function to return getMedian
    double getMedian()
    {
        if(minh.size() == maxh.size()) {
            return ((double)minh.top()+maxh.top())/2;
        } else {
            return maxh.top();
        }
        
    }
};

// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends