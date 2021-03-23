// Question:

/*
You are given string str. You need to remove the consecutive duplicates from the given string using a Stack.
 

Example 1:

Input: 
aaaaaabaabccccccc

Output: 
ababc

Explanation: 
Removing all consecutive duplicates, 
we have no duplicates consecutively.
Example 2:

Input: 
abbccbcd

Output: 
abcbcd

Explanation: 
Removing all the consecutive duplicates, 
we have the output as abcbcd.

Your Task:
This is a function problem. You need to complete the function removeConsecutiveDuplicates() that takes a string as a parameter and returns the modified string. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= |str| <= 103
*/

// Code:
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    // Function to print string after removing consecutive duplicates
    
    
    string removeConsecutiveDuplicates(string s)
    {
        stack <char> st;
        string res;
        for(int i=0;i<s.length();i++) {
            if(st.empty() == true) {
                st.push(s[i]);
                res=s[i];
            } else {
                if(st.top() != s[i]) {
                    st.push(s[i]);
                    res+=s[i];
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.removeConsecutiveDuplicates(s)<<endl;
    }
    
	return 0;
}  // } Driver Code Ends