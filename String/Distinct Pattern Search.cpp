// Question:
/*
Given a string S and a pattern P (of distinct characters) consisting of lowercase characters. The task is to check if pattern P exists in the given string S or not.
Note : Pattern has distinct characters. There might be repetitions in text.

Example 1:

Input:
S = abceabcdabceabcd
P = abcd
Output: Yes
Explanation: Given pattern abcd is
present at index 4.
Example 2:

Input:
S = abceabcdabceabcd
P = gfhij
Output: No
Explanation: Given pattern gfhij is
not found in the string.
Your Task:
The task is to complete the function search() which finds for the pattern with distinct characters. The function takes string and pattern as parameters and returns either true or false. Return true if pattern is found else return false.

Expected Time Complexity: O(N + M).
Expected Auxiliary Space: O(1).
Note: N = |S|, M = |P|.

Constraints:
1 <= |S|, |P| <= 103
*/



// Code:

// { Driver Code Starts
// C++ program for Naive Pattern 
// Searching algorithm 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


/*  function to search for a pattern with distinct characters
*   pat: pattern(to be searched in txt) given in the input
*   txt: string given in the input
*/
bool search(string pat, string txt) 
{ 
    int count =0;
	int j;
	int n= txt.length();
	int m = pat.length();
	for(int i=0;i<=n-m;i++) {
	    count = 0;
	    for(j=0;j<m;j++) {
	        if(pat[j] == txt[i+j]) {
	            count++;
	            if(count == m) {
	                return true;
	            }
	        } else {
	            break;
	        }
	    }
	    i=i+j;
	}
	return false;
} 

// { Driver Code Starts.

// Driver Code 
int main() 
{ 
	
	int t;
	cin >> t;
	
	while(t--){
	    string s, p;
	    cin >> s >> p;
	    if(search(p, s)) cout << "Yes"; else cout << "No"; cout << endl;
	}
	
	return 0; 
}  // } Driver Code Ends