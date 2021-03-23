// Question:
/*
Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
â€‹Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 
Example 1:

Input: str = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-
Explanation:
After converting the infix expression 
into postfix expression, the resultant 
expression will be abcd^e-fgh*+^*+i-
Example 2:

Input: str = "A*(B+C)/D"
Output: ABC+*D/
Explanation:
After converting the infix expression 
into postfix expression, the resultant 
expression will be ABC+*D/
 
Your Task:
This is a function problem. You only need to complete the function infixToPostfix() that takes a string(Infix Expression) as a parameter and returns a string(postfix expression). The printing is done automatically by the driver code.

Expected Time Complexity: O(|str|).
Expected Auxiliary Space: O(|str|).

Constraints:
1 ≤ |str| ≤ 105

*/

// Code:
// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The main function to convert infix expression
//to postfix expression

class Solution
{
    public:
    int precedence(char ch) {
        int s;
        switch(ch) {
            case '+':
                s = 1;
                break;
            case '-':
                s = 1;
                break;
            case '/':
                s = 2;
                break;
            case '*':
                s = 2;
                break;
            case '^':
                s = 3;
                break;
            default:
                s = 100;
        }
        return s;
        
    }
    
    string infixToPostfix(string s)
    {
        stack <char> st;
        string res="";
        for(int i=0;i<s.length();i++) {
            if(s[i]>='a' && s[i]<='z') {
                res+=s[i];
            } else if(s[i]=='(') {
                st.push(s[i]);
            } else if(s[i] == ')') {
                while(st.top() != '(') {
                    res+=st.top();
                    st.pop();
                    
                }
                st.pop();
            } else {
                if(st.empty() == false && (precedence(st.top()) < precedence(s[i]))) {
                    st.push(s[i]);
                } else {
                    while(st.empty() == false && st.top()!='(' && (precedence(st.top()) >= precedence(s[i]))) {
                        res+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
        
        while(st.empty() == false) {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        Solution ob;
        cout<<ob.infixToPostfix(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends