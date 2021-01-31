// Question:
/*
Given a string S consisting of uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

Example 1:

Input:
N = 12
S = defRTSersUXI
Output: deeIRSfrsTUX
Explanation: Sorted form of given string
with the same case of character as that
in original string is deeIRSfrsTUX
Example 2:

Input:
N = 6
S = srbDKi
Output: birDKs
Explanation: Sorted form of given string
with the same case of character will
result in output as birDKs.
Your Task:
You only need to complete the function caseSort that returns sorted string.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 103
*/

// Code:

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


string caseSort(string str, int n){
    
    map <char,int> small;
    map <char,int> caps;
    for(int i=0;i<n;i++) {
        if(str[i]>='A' && str[i]<= 'Z') {
            caps[str[i]]++;
        } else {
            small[str[i]]++;
        }
    }
    auto sitr = small.begin();
    auto citr = caps.begin();
    for(int i=0;i<n;i++) {
        if(str[i]>='A' && str[i]<= 'Z') {
            str[i]=citr->first;
            caps[citr->first]-=1;
            if(caps[citr->first] == 0) {
                caps.erase(citr->first);
                citr++;
            }
            
            
        } else {
            str[i]=sitr->first;
            small[sitr->first]-=1;
            if(small[sitr->first] == 0) {
                small.erase(sitr->first);
                sitr++;
            }
            
        }
    }
    return str;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		
		cout<<caseSort (str, n)<<endl;
	}
}  // } Driver Code Ends