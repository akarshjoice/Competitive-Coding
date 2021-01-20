// Question:
/*
You are given a string. You need to print the lexicographically sorted power-set of the string.
Note: The string s contains lowercase letter of alphabet.

Example 1:

Input:
s = a
Output: a
Explanation: empty string and a 
are only sets.
Example 2:

Input:
s = abc
Output: a ab abc ac b bc c
Explanation: empty string, 
a, ab, abc, ac, b, bc, c 
are the sets.
Your Task:
You don't need to read input or print anything. You only need to complete the function powerSet that takes string s as parameter and returns a list of subsets. The lexicographic-sorting and printing is done automatically by the driver code.

Expected Time Complexity: O(2|s|).
Expected Auxiliary Space: O(|s|). 

Constraints:
1 <= |s| <= 10
*/

// Code:
// { Driver Code Starts
//Initial Template for C++


// CPP program to generate power set
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//Complete this function

int powerset1(string s ,int l ,vector <string> &a, string d,int i)
{
    if(l == i) {
        
        a.push_back(d);
        return 0;
    }
    
    
    
    powerset1(s,l,a,d,i+1);
    powerset1(s,l,a,d+s[i],i+1);
   
    
}


vector <string> powerSet(string s)
{  
   vector <string> a;
   powerset1(s,s.length(),a,"",0);
   //sort(a.begin(),a.end());
   return a;
}


// { Driver Code Starts.


// Driver code
int main()
{
    int T;
    cin>>T;//testcases
    while(T--)
    {
        string s;
        cin>>s;//input string
        
        //calling powerSet() function
        vector<string> ans = powerSet(s);
        
        //sorting the result of the powerSet() function
        sort(ans.begin(),ans.end());
        
        //printing the result
        for(auto x:ans)
        cout<<x<<" ";
        cout<<endl;
        
        
    }

return 0;
}   // } Driver Code Ends