// Question:
/*
Given N integer ranges, the task is to find the maximum occurring integer in these ranges. If more than one such integer exits, find the smallest one. The ranges are given as two arrays L[] and R[].  L[i] consists of starting point of range and R[i] consists of corresponding end point of the range.

For example consider the following ranges.
L[] = {2, 1, 3}, R[] = {5, 3, 9)
Ranges represented by above arrays are.
[2, 5] = {2, 3, 4, 5}
[1, 3] = {1, 2, 3}
[3, 9] = {3, 4, 5, 6, 7, 8, 9}
The maximum occurred integer in these ranges is 3.

Example 1:

Input:
N = 4
L[] = {1,4,3,1}
R[] = {15,8,5,4}
Output: 4
Explanation: The given ranges are [1,15]
 [4, 8] [3, 5] [1, 4]. The number that 
is most common or appears most times in 
the ranges is 4.

Example 2:

Input:
N = 5
L[] = {1,5,9,13,21}
R[] = {15,8,12,20,30}
Output: 5
Explanation: The given ranges are 
[1,15] [5, 8] [9, 12] [13, 20] 
[21, 30]. The number that is most 
common or appears most times in 
the ranges is 5.

Your Task:
The task is to complete the function maxOccured() which returns the maximum occured integer in all ranges.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(maxx).
-maxx is maximum element in R[]


Constraints:
1 <= n <= 106
0 <= L[i], R[i] <= 10^6
*/


// Code:
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;




 // } Driver Code Ends


// L and R are input array
// maxx : maximum in R[]
// n: size of array
// arr[] : declared globally with size equal to maximum in L[] and R[]
int maxOccured(int L[], int R[], int n, int maxx){
  int arr[maxx+1]; 
   for(int i=0;i<maxx+1;i++)
      {arr[i]=0;
      }
    for (int i = 0; i < n; i++) 
    { 
        arr[L[i]] += 1; 
        arr[R[i] + 1] -= 1;
        } 
    
    int sum = arr[0],ind; 
    for (int i = 1; i < maxx+1; i++) 
    { 
        arr[i] += arr[i - 1]; 
        if (sum < arr[i]) 
        {  if(arr[i]!=sum)
              {sum = arr[i]; 
               ind = i;
              }
        } 
    } 
  
    return ind;  
    
}

// { Driver Code Starts.

int main() {
	
	int t;
	
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n;
	    
	    //taking size of array
	    cin >> n;
	    int L[n];
	    int R[n];
	    
	    //adding elements to array L
	    for(int i = 0;i<n;i++){
	        cin >> L[i];
	    }
	    
	    int maxx = 0;
	    
	    //adding elements to array R
	    for(int i = 0;i<n;i++){
	        
	        cin >> R[i];
	        if(R[i] > maxx){
	            maxx = R[i];
	        }
	    }
	    
	    //calling maxOccured() function
	    cout << maxOccured(L, R, n, maxx) << endl;
	}
	
	return 0;
}  // } Driver Code Ends