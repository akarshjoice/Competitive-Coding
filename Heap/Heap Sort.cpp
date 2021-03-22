// Question:
/*
Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.


Example 1:

Input:
N = 5
arr[] = {4,1,3,9,7}
Output:
1 3 4 7 9
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1,3,4,7,9.
Example 2:

Input:
N = 10
arr[] = {10,9,8,7,6,5,4,3,2,1}
Output:
1 2 3 4 5 6 7 8 9 10
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1, 2,3,4,5,6,7,8,9,10.

Your Task :
You don't have to read input or print anything. Your task is to complete the functions heapify(), buildheap() and heapSort() where heapSort() and buildheap() takes the array and it's size as input and heapify() takes the array, it's size and an index i as input. Complete and use these functions to sort the array using heap sort algorithm.


Expected Time Complexity: O(N * Log(N)).
Expected Auxiliary Space: O(1).


Constraints:
1 <= N <= 106
1 <= arr[i] <= 106
*/

// Code:
// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    int left(int i) {
        return (2*i)+1;
    }
    
    int right(int i) {
        return (2*i)+2;
    }
    void heapify(int a[], int n, int i)  {
      
      while(1) {
          int small = i;
          if(left(i) < n && a[small]<a[left(i)]) {
              small = left(i);
          }
          if(right(i) < n && a[small]<a[right(i)]) {
              small = right(i);
          }
          if(small != i) {
              int tmp;
              tmp = a[small];
              a[small] = a[i];
              a[i] = tmp;
              i = small;
          } else {
              break;
          }
      } 
    }

    public:
    void buildHeap(int a[], int n)  { 
        int p = floor((n-1)/2);
        for(int i=p;i>=0;i--) {
            heapify(a,n,i);
        } 
    }

    
    public:
    void heapSort(int a[], int n)
    {
        buildHeap(a,n);
        int p = n;
        vector <int> l;
        int tmp;
        for(int i=0;i<p;i++) {
            //l.push_back(a[0]);
            tmp = a[0];
            a[0] = a[n-1];
            a[n-1] = tmp;
            n--;
            heapify(a,n,0);
        }
       /* for(int i=0;i<l.size();i++) {
            a[i] = l[i];
        }*/
        
    }
};




// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends