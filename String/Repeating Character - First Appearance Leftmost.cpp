// Question:
/*
You are given a string S (both uppercase and lowercase characters). You need to print the repeated character whose first appearance is leftmost.

Example 1:

Input:
S = geeksforgeeks
Output: g
Explanation: We see that both e and g
repeat as we move from left to right.
But the leftmost is g so we print g.
Example 2:

Input:
S = abcd
Output: -1
Explanation: No character repeats so
we print -1.
Your Task:
This is a function problem. You only need to complete the function repeatedCharacter() that takes a string as a parameter and returns the index of the character. If no character repeats then return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).

Constraints:
1 <= |S| <= 100
*/



// Code:

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//Back-end complete function Template for C++

//Return the index of the character or return -1
int repeatedCharacter (string s) 
{ 
    unordered_map <char,int> mp;
    
    int pos=s.length();
    for(int i=0;i<s.length();i++) {
        if(mp.count(s[i])!=1) {
            mp.insert({s[i],i});
        } else {
            if(mp[s[i]]<pos) {
                pos=mp[s[i]];
            }
        }
    }
    if(pos!=s.length()) {
        return pos;
    }
    return -1;
    
} 
    

// { Driver Code Starts.


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    int index = repeatedCharacter(s); 
        if (index == -1) 
            cout<<-1<<endl;
        else
            cout<<s[index]<<endl;
	}
	return 0;
}
  // } Driver Code Ends