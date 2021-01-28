// Question:
/*
Given a string S and a pattern P both of lowercase characters. The task is to check if the given pattern exists in the given string or not.

Example 1:

Input:
S = aabaacaadaabaaabaa
P = aaba
Output: Yes
Explanation: Given pattern aaba is found
in the string at index 0.
Example 2:
Input:
S = aabaacaadaabaaabaa
P = ccda
Output: No
Explanation: Given pattern ccda doesn't
exists in the string at all.
Your Task:
The task is to complete the function search() which finds the pattern in the given string. The function takes pattern and string as parameters and returns either true or false. Return true if pattern exists else return false.

Expected Time Complexity: O(N*M).
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


/*  Function to serach pattern in the given string
*   pat: pattern given in input
*   txt: string given in the input
*/
bool search(string pat, string txt) 
{ 
	
	return (txt.find(pat) != string::npos);
	
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
}
  // } Driver Code Ends