// Question:
/*
Given a string str. The task is to find the maximum occurring character in the string str. If more than one character occurs the maximum number of time then print the lexicographically smaller character.

Example 1:

Input:
str = testsample
Output: e
Explanation: e is the character which
is having the highest frequency.
Example 2:

Input:
str = output
Output: t
Explanation:  t and u are the characters
with the same frequency, but t is
lexicographically smaller.
Your Task:
The task is to complete the function getMaxOccuringChar() which returns the character which is most occurring.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).
Note: N = |s|

Constraints:
1 ≤ |s| ≤ 100
*/


// Code:

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

char getMaxOccuringChar(char*);

int main()
{
   
    char str[100];
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%s",str);
    cout<< getMaxOccuringChar(str)<<endl;
    }
}// } Driver Code Ends


// Function to get maximum occuring 
// character in given string str
char getMaxOccuringChar(char* str)
{
    map <int,int> mp;
    
    int max=-1;
    for(int i=0;i<strlen(str);i++) {
        mp[str[i]]++;
        if(mp[str[i]]>max) {
            max=mp[str[i]];
        }
        
    }
    
    for(auto i:mp) {
        if(i.second==max)   
                return i.first;
    }
}