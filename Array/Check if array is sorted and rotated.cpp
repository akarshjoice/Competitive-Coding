// Question:
/*
Given an array arr[] of N distinct integers, check if this array is Sorted (non-increasing or non-decreasing) and Rotated counter-clockwise. Note that input array may be sorted in either increasing or decreasing order, then rotated.
A sorted array is not considered as sorted and rotated, i.e., there should be at least one rotation.

Example 1:

Input:
N = 4
arr[] = {3,4,1,2}
Output: Yes
Explanation: The array is sorted 
(1, 2, 3, 4) and rotated twice 
(3, 4, 1, 2).
Example 2:

Input:
N = 3
arr[] = {1,2,3}
Output: No
Explanation: The array is sorted 
(1, 2, 3) is not rotated.
Your Task:
The task is to complete the function checkRotatedAndSorted() which returns true if an array is sorted and rotated clockwise otherwise false.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 10^6
1 <= A[i] <= 10^6
*/


// Code
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// arr: input array
// num: length of array
// This function returns true or false

bool checkRotatedAndSorted(int a[], int n){
    /*dec-1
      asc-0
    */
    int pos = 0;
    int flag = (a[0]<a[1])?0:1;
    for(int i=1;i<n;i++) {
        if(a[i-1]<a[i] && flag==1) {
            
            pos =i-1;
            break;
        } else if(a[i-1]>a[i] && flag==0){
            pos =i-1;
            break;
        }
    }
    flag = 0;
    if(pos == 0) {
        return 0;
    }
    
    for(int i=(pos+2)%n;i!=pos;i=(i+1)%n) {
        int j=i-1;
        if(j==-1) {
                j=n-1;
        }
        if(flag==0) {
            
            
            if(a[i]<a[j]) {
                flag = 1;
            } else if(a[i]>a[j]) {
                flag = 2;
            }
        } else if(flag == 2) {
            if(a[i]<a[j]) {
                return 0;
            }
        } else if(flag == 1) {
            if(a[i]>a[j]) {
                return 0;
            }
        }
    }
    
    //cout<<pos<<" ";
    return 1;
    
}

// { Driver Code Starts.

int main()
 {
	int T;
	//testcases
	cin>> T;
	
	while (T--){
	    int num;
	    //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for(int i = 0; i<num; ++i)
            cin>>arr[i];
        
        bool flag = false;
        
        //function call
        flag = checkRotatedAndSorted(arr, num);
        
        //printing "No" if not sorted and
        //rotated else "Yes"
        if(!flag){
            cout << "No"<<endl;
        }
        else
        cout << "Yes"<<endl;
    
	}
	
	return 0;
}  // } Driver Code Ends