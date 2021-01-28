// Question:

/*
Given a string str and another string patt. Find the character in patt that is present at the minimum index in str. If no character of patt is present in str then print ‘No character present’.

Example 1:

Input:
str = geeksforgeeks
patt = set
Output: e
Explanation: e is the character which is
present in given patt "geeksforgeeks"
and is first found in str "set".
Example 2:

Input:
str = adcffaet
patt = onkl
Output: No character present
Explanation: There are none of the
characters which is common in patt
and str.
Your Task:
You only need to complete the function minIndexChar() that returns the index of answer in str or returns -1 in case no character of patt is present in str.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).

Constraints:
1 <= |str|,|patt| <= 105
*/

// Code:

// { Driver Code Starts
// C++ implementation to find the character in first 
// string that is present at minimum index in second
// string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


int minIndexChar(string str, string patt)
{
    unordered_map <char,int> mp;
    for(int i=0;i<str.length();i++) {
        if(mp.count(str[i]) == 1) {
            continue;
        } else {
            mp.insert({str[i],i});
        }
    }
    
    int minval = INT_MAX;
    for(int i=0;i<patt.length();i++) {
        if(mp.count(patt[i]) == 1) {
            minval = min(minval,mp[patt[i]]);
        }
    }
    if(minval == INT_MAX) {
        return -1;
    } else {
        return minval;
    }
}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    string patt;
	    cin>>str;
	    cin>>patt;
	    int ans = minIndexChar(str, patt);
	    if(ans == -1)cout<<"No character present";
	    else cout<<str[ans];
	    cout<<endl;
	}return 0;
}
  // } Driver Code Ends