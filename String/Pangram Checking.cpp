// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Returns true if the string is pangram else false
bool checkPangram (string &str)
{
    int a[26] = {0};
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    for(int i=0;i<str.length();i++) {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {
            a[str[i] - 'a']=1;
        }
        
    }
    for(int i=0;i<26;i++) {
        if(a[i] == 0) {
            return 0;
        }
    }
    return 1;
}



// { Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        
        if (checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}
  // } Driver Code Ends