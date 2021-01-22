// Question:
/*
You are given an array arr. The size of the array is given by sizeOfArray. You need to insert an element at the end.

Example 1:

Input:
sizeOfArray = 6
arr[] = {1, 2, 3, 4, 5}
element = 90
Output: 1 2 3 4 5 90
Explanation: After inserting 90 at the
end, we have array elements as 
1 2 3 4 5 90.
Example 2:

Input:
sizeOfArray = 4
arr[] = {1, 2, 3}
element = 50
Output: 1 2 3 50
Explanation: After inserting 50 at the 
end, we have array elements as 
1 2 3 50.
Your Task:
You don't need to read input or print anything. You only need to complete the function insertAtEnd() that takes arr, sizeOfArray, element as input and modifies arr as per requirements. The driver code takes care of the printing.

Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).

Constraints:
2 <= sizeOfArray <= 1000
0 <= element, arri <= 10^6
*/


// Code:
// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

void insertAtEnd(int arr[],int sizeOfArray,int element);


 // } Driver Code Ends


//User function Template for C++


// You only need to insert the given element at 
// the end, i.e., at index sizeOfArray - 1. You may 
// assume that the array already has sizeOfArray - 1
// elements. 
void insertAtEnd(int arr[],int sizeOfArray,int element)
{
    arr[sizeOfArray-1] = element;
}



// { Driver Code Starts.

int main() {
    int t;
    
    //taking testcases
    cin>>t;
    while(t--)
    {
        int sizeOfArray;
        
        //input size of Array
        cin>>sizeOfArray;
        
        int arr[sizeOfArray];
        
        //inserting elements in the array
        for(int i=0;i<sizeOfArray-1;i++)
        cin>>arr[i];
        
        //input element to be inserted
        int element;
        cin>>element;
        
        //calling insertAtEnd() function
        insertAtEnd(arr,sizeOfArray,element);
        
        //printing the elements of the array
        for(int i=0;i<sizeOfArray;i++)
        cout<<arr[i]<<" ";
        
        cout<<endl;
        
    }
    
	return 0;
}  // } Driver Code Ends