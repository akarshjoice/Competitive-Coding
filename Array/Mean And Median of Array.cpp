// Question:
/*
Given an array a[ ] of size N. The task is to find the median and mean of the array elements. Mean is average of the numbers and median is the element which is smaller than half of the elements and greater than remaining half.  If there are odd elements, the median is simply the middle element in the sorted array. If there are even elements, then the median is floor of average of two middle numbers in the sorted array. If mean is floating point number, then we need to print floor of it.

Note: To find the median, you might need to sort the array. Since sorting is covered in later tracks, we have already provided the sort function to you in the code.

Example 1:

Input:
N = 5
a[] = {1, 2, 19, 28, 5}
Output: 11 5
Explanation: For array of 5 elements,
mean is (1 + 2 + 19  + 28  + 5)/5 = 11.
Median is 5 (middle element after 
sorting)
Example 2:

Input:
N = 4
a[] = {2, 8, 3, 4}
Output: 4 3
Explanation: For array of 4 elements,
mean is floor((2 + 8 + 3 + 4)/4) = 4.
Median is floor((4 + 3)/2) = 3
Your Task:
You don't need to read input or print anything.. You just need to complete the following two function:

mean(): It takes the array and its size N as parameters and returns the mean as an integer.
median(): It takes the array and its size N as parameters and returns the median as an integer.
Expected Time Complexity: O(N log(N)).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
1 <= a[i] <= 10^6
*/


// Code:
// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

int median(int a[],int N)
{
    
    sort(a,a+N);
    int p;
    if(N%2 == 0) {
        p = (a[(N/2)-1] + a[(N/2)])/2;
    } else {
        p = a[N/2];
    }
    return p;
    
    //your code here
    //If median is in fraction then convert it to integer and return
}

int mean(int a[],int N)
{   
    int sum = 0;
    for(int i=0;i<N;i++) {
        sum+=a[i];
    }
    return (sum/N);
}


// { Driver Code Starts.

int main()
{
    //testcase
    int T;
    cin>>T;
   
    //looping testcase
    while(T--)
    {
        //number of elements in array
        int N;
        cin>>N;
        int a[N];
        
        //inseting elements in the array
        for(int i=0;i<N;i++){
            cin>>a[i];
        }
        //calling mean() and median() functions
        cout<<mean(a,N)<<" "<<median(a,N)<<endl;
    }
    return 0;
}
  // } Driver Code Ends