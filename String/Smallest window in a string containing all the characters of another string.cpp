// Question:
/*
Given two strings. Find the smallest window in the first string consisting of all the characters of the second string.

Example 1:

Input:
S = timetopractice
P = toc
Output: toprac
Explanation: toprac is the smallest
subset in which toc can be found.
Example 2:

Input:
S = zoomlazapzo
P = oza
Output: apzo
Explanation: To find oza in the
zoomlazapzo the smallest subset is
apzo.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smallestWindow() which takes two string S and P as inputs and returns the smallest window in string S having all the characters of the string P. In case there are multiple such windows of same length, return the one with the least starting index. Return "-1" in case there's no such window present. 

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints: 
1 <= |S|, |P| <= 1000
*/



// Code:
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// return the smallest window in S with all the characters of P
// if no such window exists, return "-1" 
string smallestWindow (string S, string P){
 
     int a[26]={0};
     int b[26]={0};
     
     for(int i=0;i<P.length();i++) {
         a[P[i]-'a']++;
         
     }
     int count=0;
     int m=INT_MAX;
     int start=0;
     int res=0;
     int flag=0;
     for(int i=0;i<S.length();i++) {
         b[S[i]-'a']++;
         if(a[S[i]-'a']>=0 && b[S[i]-'a']<=a[S[i]-'a']) {
             count++;
         }
         
         if(count==P.length()) {
             int flag=1;
             while(start<i && b[S[start]-'a']>a[S[start]-'a']) {
                 
                 b[S[start]-'a']--;
                 start++;
             }
             if((i-start+1) < m) {
                 m=i-start+1;
                 res=start;
             }
         }
     }
     
     if(count==P.length()) {
        string p=S.substr(res,m);
        return p;
     }
     return "-1";
  
}

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        
        cout<<smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends