// Question:
/*
You are given string str. You need to remove the pair of duplicates.
Note: The pair should be of adjacent elements and after removing a pair the remaining string is joined together. 

Example 1:

Input:
aaabbaaccd

Output: 
ad

Explanation: 
Remove (aa)abbaaccd =>abbaaccd
Remove a(bb)aaccd => aaaccd
Remove (aa)accd => accd
Remove a(cc)d => ad
Example 2:

Input: 
aaaa

Output: 
Empty String

Explanation: 
Remove (aa)aa => aa
Again removing pair of duplicates then (aa) 
will be removed and we will get 'Empty String'.

Your Task:
This is a function problem. You only need to complete the function removePair() that takes a string as a parameter and returns the modified string. Return an empty string if the whole string is deleted.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
N = length of the string.

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
    // Function to return string after removing consecutive duplicates
    
    // Function to remove pair of characters
    string removePair(string str){
        
        stack <char> st;
        for(int i=0;i<str.length();i++) {
            if(st.empty()) {
                st.push(str[i]);
            } else {
                if(st.top() == str[i]) {
                    st.pop();
                } else {
                    st.push(str[i]);
                }
            }
        }
        string s="";
        while(st.empty() == false) {
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(), s.end()); 
        return s;
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
        string ans = obj.removePair (s);
        if(ans=="")
            cout<<"Empty String"<<endl;
        else
            cout<<ans<<endl;
    }
    
	return 0;
}  // } Driver Code Ends