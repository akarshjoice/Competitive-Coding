// Question:
/*
You are given a string S of lowercase characters, find the rank of the string amongst its permutations when sorted lexicographically. Return 0 if the characters are repeated in the string.
Note: Return the rank%1000000007 as the answer as rank might overflow.

Example 1:

Input:
S = abc
Output: 1
Explanation: In 'abc' when we sort all the
permutations in lexicographic order 'abc'
will be at the first position.
Example 2:

Input:
S = acb
Output: 2
Explanation: In 'acb' .The
lexicographically sorted permutations
with letters 'a', 'c', and 'b' will be
at second position. 
Your Task:
You only need to complete the function findRank that takes string S as a parameter and returns the rank.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ |S| ≤ 15
*/

// Code:
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


int fact(int n)
{
    if(n <= 1)
    return 1;
    return n * fact(n-1);
}

int findRank(string str)
{
    int res = 1;
    int n = str.size();
    int mul = fact(n);
    int counter[256] = {0};
    
    map <char,int> mp;
    for(int i=0;i<n;i++) {
        if(mp.count(str[i])==1) {
            return 0;
        }
        mp.insert({str[i],1});
    }
    
    
    for(int i = 0; i < n; i++)
    {
        counter[str[i]]++;
    }
    
    for(int i = 1; i < 256; i++)
    {
       counter[i] += counter[i-1];
    }
    
    for(int i = 0; i < n; i++)
    {
       mul = mul/(n-i);
     
       res += (counter[str[i]-1] * mul);
    
        for(int j = str[i]; j < 256; j++)
        {
            counter[j]--;
        }
    }

    return res%1000000007;
}
    

// { Driver Code Starts.


int main()
{
    string S;
    int t;
    cin>>t;
    while(t--)
    {
     
        cin>>S;
    cout<<findRank(S)<<endl;
    }
}
  // } Driver Code Ends