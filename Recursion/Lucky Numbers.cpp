// Question:
/*
Lucky numbers are subset of integers. Rather than going into much theory, let us see the process of arriving at lucky numbers,
Take the set of integers
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,……
First, delete every second number, we get following reduced set.
1, 3, 5, 7, 9, 11, 13, 15, 17, 19,…………
Now, delete every third number, we get
1, 3, 7, 9, 13, 15, 19,….….
Continue this process indefinitely……
Any number that does NOT get deleted due to above process is called “lucky”.

Example 1:

Input:
N = 5
Output: 0
Explanation: 5 is not a lucky number 
as it gets deleted in the second 
iteration.
Example 2:

Input:
N = 19
Output: 1
Explanation: 19 is a lucky number
Your Task:
You don't need to read input or print anything. You only need to complete the function isLucky that takes n as parameter and returns either 0 if the n is not lucky else 1.

Expected Time Complexity: O(sqrt(n)).
Expected Auxiliary Space: O(sqrt(n)).

Constraints:
1 <= N <= 10^5
*/


// Code:
//Initial Template for C++


#include <bits/stdc++.h>
#define ll long long 
using namespace std;



 // } Driver Code Ends


//User-function template for C++

// Complete the function
// n: Input n
// counter: variable has already been declared in driver code and initialized as 2
// Return True if the given number is a lucky number else return False

bool isLucky(int n, int &counter) {
  if(counter>n) {
      return true;
  }
  
  if(n%counter == 0) {
      return  false;
  }
  n = n - (n/counter);
  counter = counter+1;
  return isLucky(n,counter);
 
}


// { Driver Code Starts.

/*Driver function to test above function*/
int main() {
    int t;
    cin >> t;//testcases
    while(t--) {
        int n;
        cin>>n;//input n
        int counter = 2;
        
        //calling isLucky() function
        if(isLucky(n, counter))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    return 0;
}  // } Driver Code Ends