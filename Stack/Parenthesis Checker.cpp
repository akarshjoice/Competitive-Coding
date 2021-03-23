// Question:

/*
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    // Function to return if the paranthesis are balanced or not
    bool check_match(char s,char f) {
        if((f=='(' && s == ')') || (f=='{' && s == '}') || (f=='[' && s == ']')) {
            return true;
        }
        return false;
    }
    bool ispar(string x)
    {
        stack <char> st;
        for(int i=0;i<x.length();i++) {
            if(st.empty() == true) {
                st.push(x[i]);
            } else {
                if(check_match(x[i],st.top()) == true) {
                    st.pop();
                } else {
                    st.push(x[i]);
                }
            }
        }
        if(st.empty() == true) {
            return true;
        } else {
            return false;
        }
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends

*/

// Code:
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    // Function to return if the paranthesis are balanced or not
    bool check_match(char s,char f) {
        if((f=='(' && s == ')') || (f=='{' && s == '}') || (f=='[' && s == ']')) {
            return true;
        }
        return false;
    }
    bool ispar(string x)
    {
        stack <char> st;
        for(int i=0;i<x.length();i++) {
            if(st.empty() == true) {
                st.push(x[i]);
            } else {
                if(check_match(x[i],st.top()) == true) {
                    st.pop();
                } else {
                    st.push(x[i]);
                }
            }
        }
        if(st.empty() == true) {
            return true;
        } else {
            return false;
        }
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends