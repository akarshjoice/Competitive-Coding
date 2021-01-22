// Question:
/*
You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing 
number is 6.
Example 2:

Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2
Explanation: Smallest positive missing 
number is 2.
Your Task:
The task is to complete the function missingNumber() which returns the smallest positive missing number in the array.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 10^6
-106 <= arr[i] <= 10^6
*/

// Code:
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Functio to find first smallest positive
// missing number in the array
int missingNumber(int a[], int n) { 
   

   
   int max=INT_MIN;
   int k = n+5;
   for(int i=0;i<n;i++) {
       if(a[i]<=0) {
           a[i] = k++;
       }
       if(a[i]>max){
           max = a[i];
       }
   }
   max=max+1;
   for(int i=0;i<n;i++) {
       if((abs(a[i]%max))>=1 && abs((a[i]%max))<=n && a[abs((a[i]%max))-1]>0)
         {    a[abs((a[i]%max))-1] += (abs(a[i]%max))*max;
              a[abs((a[i]%max))-1] = -1*a[abs((a[i]%max))-1];
         }
   }
   
   
   for(int i=0;i<n;i++) {
       if(a[i]<0) {
           a[i]=-1*a[i];
       }
       a[i]/=max;
   }
   for(int i=0;i<n;i++) {
       if(a[i] != (i+1)) {
           return (i+1);
       }
   }
   return (n+1);
    
}
    // Your code here
// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        //calling missingNumber()
        cout<<missingNumber(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends