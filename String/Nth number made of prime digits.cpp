// Question:
/*
Given a number 'N'. The task is to find the Nth number whose each digit is a prime number i.e 2, 3, 5, 7. In other words you have to find nth number of this sequence : 2, 3, 5, 7, 22, 23 ,.. and so on.

Example 1:

Input:
N = 10
Output: 33
Explanation:10th number in the sequence of
numbers whose each digit is prime is 33.
Example 2:

Input:
N = 21
Output: 222
Explanation:21st number in the sequence of
numbers whose each digit is prime is 222.
Your Task:
Complete primeDigits function and return the nth number of the given sequence made of prime digits.

Constraints:
1 <= N <= 100
*/


// Code:

// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

int primeDigits(int );

int main()
{
    int t;
    cin>>t;
    // All the above tasks are preprocessing, now you can run testcases
    // and then print the values accordingly
    while(t--)
    {
        int n;
        cin>>n;
        cout << primeDigits(n) << "\n";   
    }
}
// } Driver Code Ends


//User function template for C++

// n : given integer value

int primeDigits(int t) {
    string s;
    int n = t;
    while( n != 0) {
        if((n%4) == 1) {
            s="2"+s;
        } else if((n%4) == 2) {
            s="3"+s;
        } else if((n%4) == 3) {
            s="5"+s;
        } else if((n%4) == 0) {
            s ="7"+s;
        }
        if(n%4 == 0) {
            n--;
        }
        n = n/4;
    }
    int p = stoi(s);
    return p;
}