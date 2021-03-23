// Question:

/*
Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

 

Example 1:

Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression, 
we have -4 as result.
 

Example 2:

Input: S = "123+*8-"
Output: -3
Explanation:
After solving the given postfix 
expression, we have -3 as result.

Your Task:
You do not need to read input or print anything. Complete the function evaluatePostfixExpression() that takes the string S denoting the expression as input parameter and returns the evaluated value.


Expected Time Complexity: O(|S|)
Expected Auixilliary Space: O(|S|)


Constraints:
1 ≤ |S| ≤ 105
*/

// Code:
// { Driver Code Starts
// C++ program to evaluate value of a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // The main function that returns value of a given postfix expression
    int eval(int a,int b, char ch) {
        if(ch == '+') {
            return a+b;
        } else if(ch == '-') {
            return a-b;
        } else if(ch == '*') {
            return  a*b;
        } else {
            return a/b;
        }
    }
    
    
    int evaluatePostfix(string s)
    {
        stack<string> st;
        for(int i=0;i<s.length();i++) {
            if(s[i]>='0' && s[i]<='9') {
                string tmp="";
                tmp+=s[i];
                st.push(tmp);
            } else {
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                string res = to_string(eval(b,a,s[i]));
                
                //cout<<b<<" "<<s[i]<<" "<<a<<" = "<<res<<endl;
                st.push(res);
            }
        }
        return stoi(st.top());
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends