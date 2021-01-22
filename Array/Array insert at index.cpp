// Question:
/*
You are given an array arr(0-based index). The size of the array is given by sizeOfArray. You need to insert an element at given index and print the modified array.

Example 1:

Input:
sizeOfArray = 6
arr[] = {1, 2, 3, 4, 5}
index = 5, element = 90
Output: 1 2 3 4 5 90
Explanation: 90 is inserted at index
5(0-based indexing). After inserting,
array elements are like
1, 2, 3, 4, 5, 90.
Example 2:

Input:
sizeOfArray = 6
arr[] = {1, 2, 3, 4, 5}
index = 2, element = 90
Output: 1 2 90 3 4 5
Explanation: 90 is inserted at index 
2(0-based indexing). After inserting,
array elements are like 
1, 2, 90, 3, 4, 5.
Your Task:
You don't need to read input or print anything.. The input is already taken care of by the driver code. You only need to complete the function insertAtIndex() that takes arr, sizeOfArray, index, element as input and modifies the array arr as per requirements. The printing is done by driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
2 <= sizeOfArray <= 1000
0 <= element, arri <= 106
0 <= index <= sizeOfArray-1
*/


// Code:
// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

void insertAtIndex(int arr[],int sizeOfArray,int index,int element);

 // } Driver Code Ends


//User function Template for C++

// You need to insert the given element at the given index. 
// After inserting the elements at index, elements
// from index onward should be shifted one position ahead
// You may assume that the array already has sizeOfArray - 1
// elements.
void insertAtIndex(int a[], int sizeOfArray, int index, int element)
{
    
    for(int i=sizeOfArray-1; i>=index;i--) {
        a[i]=a[i-1];
    }
    a[index] = element;
    
    
}


// { Driver Code Starts.

int main() {
    int t;
    cin>>t;//Input testcases
    while(t--)
    {
        
        int sizeOfArray; 
        
        //input size of Array
        cin>>sizeOfArray;
        
        int arr[sizeOfArray];
        
        //input elements in the Array
        for(int i = 0; i < sizeOfArray-1; i++)
        cin>>arr[i];
        
        int index;
        //input index
        cin>>index;
        int element;
        //input element
        cin>>element;
        
        //calling insertAtIndex() function
        insertAtIndex(arr, sizeOfArray, index, element); //Complete this function
        
        for(int i = 0; i < sizeOfArray; i++)//Printing the array for verification
        cout<<arr[i]<<" ";
        
        cout<<endl;
        
    }
    
	return 0;
}  // } Driver Code Ends