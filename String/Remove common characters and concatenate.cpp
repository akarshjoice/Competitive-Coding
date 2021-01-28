// Question:
/*
Given two strings s1 and s2. Modify both the strings such that all the common characters of s1 and s2 are to be removed and the uncommon characters of s1 and s2 are to be concatenated.
Note: If all characters are removed print -1.

Example 1:

Input:
s1 = aacdb
s2 = gafd
Output: cbgf
Explanation: The common characters of s1
and s2 are: a, d. The uncommon characters
of s1 and s2 are c, b, g and f. Thus the
modified string with uncommon characters
concatenated is cbgf.
Example 2:

Input:
s1 = abcs
s2 = cxzca
Output: bsxz
Explanation: The common characters of s1
and s2 are: a,c. The uncommon characters
of s1 and s2 are b,s,x and z. Thus the
modified string with uncommon characters
concatenated is bsxz.
Your Task:
The task is to complete the function concatenatedString() which removes the common characters, concatenates, and returns the string. If all characters are removed then return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).
Note: N = |Length of Strings|

Constraints: 
1 <= |Length of Strings| <= 104
*/


// Code:

// { Driver Code Starts
// C++ program Find concatenated string with 
// uncommon characters of given strings 
#include <bits/stdc++.h> 
using namespace std; 

string concatenatedString(string, string);

/* Driver program to test above function */
int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
    	string s1, s2;
    	cin >> s1 >> s2;
    	string res = concatenatedString(s1, s2);
    	cout<<res<<endl;
	}
	return 0; 
}
// } Driver Code Ends


// Function which concatenate two strings
// after removing common characters
string concatenatedString(string s1, string s2) 
{ 
    unordered_set <char> st1,st2;
    for(int i=0;i<s1.length();i++) {
        st1.insert(s1[i]);
    }
    
    for(int i=0;i<s2.length();i++) {
        st2.insert(s2[i]);
    }
    
    string a ="";
    for(int i=0;i<s1.length();i++) {
        if(st2.count(s1[i]) != 1) {
            a+=s1[i];
        }
    }
    
    for(int i=0;i<s2.length();i++) {
        if(st1.count(s2[i]) != 1) {
            a+=s2[i];
        }
    }
    if(a == "") {
        return "-1";
    }
    return a;
}
