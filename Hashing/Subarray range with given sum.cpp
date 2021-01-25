// Questions:
/*
Given an unsorted array of integers and a sum. The task is to count the number of subarray which adds to the given sum.

Example 1:

Input:
N = 5
arr[] = {10,2,-2,-20,10}
sum = -10
Output: 3
Explanation: Subarrays with sum -10 are: 
[10, 2, -2, -20], [2, -2, -20, 10] and 
[-20, 10].
Example 2:

Input:
N = 6
arr[] = {1,4,20,3,10,5}
sum = 33
Output: 1
Explanation: Subarray with sum 33 is: 
[20,3,10].
Your Task:
This is a function problem. You only need to complete the function subArraySum() that takes arr, n, sum as parameters and returns the count of subarrays which adds up to the given sum. 

Constraints:
1 <= N <= 105
-105 <= arr[i] <= 105
-105 <= sum <= 105
*/



// Code:
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int subArraySum(int arr[], int n, int sum);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    cout<<subArraySum(arr, n, sum)<<endl;
	}
	return 0;
}// } Driver Code Ends


int subArraySum(int a[], int n, int sum)
{
    unordered_map <int,int> mp;
    int sum1 = 0;
    int count = 0;
    for(int i=0;i<n;i++) {
        sum1+=a[i];
        if(mp.count(sum1-sum) == 1) {
            count+=mp[sum1-sum];
        }
        if(sum1 == sum) {
            count++;
        }
        mp[sum1]++;
    }
    return count;
}