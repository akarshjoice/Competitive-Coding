// Question:
/*
You are given a string S of alphabet characters and the task is to find its matching decimal representation as on the shown keypad. Output the decimal representation corresponding to the string. For ex: if you are given “amazon” then its corresponding decimal representation will be 262966.



Example 1:

Input:
S = geeksforgeeks
Output: 4335736743357
Explanation:geeksforgeeks is 4335736743357
in decimal when we type it using the given
keypad.
Example 2:

Input:
S = geeksquiz
Output: 433577849
Explanation: geeksquiz is 433577849 in
decimal when we type it using the given
keypad.
Your Task:
Complete printNumber() function that takes string s and its length as parameters and returns the corresponding decimal representation of the given string as a string type. The printing is done by the driver code.

Constraints:
1 ≤ length of String ≤ 100

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)
*/



// Code:
// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

string printNumber(string , int);

// User function pasted here
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s,temp;
		cin>>s;
		int i,len=s.length();
		
		cout << printNumber(s,len) << "\n";
	}
	return 0;
}// } Driver Code Ends


//User function template for C++


//s : given string 
// n: size of the given string
// return output string represents s in numbers

string printNumber(string s, int n) {
    string temp="";
    for(int i=0;i<n;i++) {
		if(s[i]=='a' || s[i]=='b' || s[i]=='c') 
		    temp+="2";
		else if(s[i]=='d' || s[i]=='e' || s[i]=='f')
		    temp+="3";
		else if(s[i]=='i' || s[i]=='g' || s[i]=='h')
		    temp+="4";
		else if(s[i]=='j' || s[i]=='k' || s[i]=='l') 
		    temp+="5";
		else if(s[i]=='m' || s[i]=='n' || s[i]=='o')
		    temp+="6";
		else if(s[i]=='p' || s[i]=='q' || s[i]=='r' || s[i]=='s')
		    temp+="7";
		else if(s[i]=='t' || s[i]=='u' || s[i]=='v') 
		    temp+="8";
		else temp+="9";
	}
	return temp;
}
