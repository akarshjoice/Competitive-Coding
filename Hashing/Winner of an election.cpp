// Question:
/*
Given an array of names (consisting of lowercase characters) of candidates in an election. A candidate name in array represents a vote casted to the candidate. Print the name of candidate that received Max votes. If there is tie, print lexicographically smaller name.

Example 1:

Input:
N = 13
Votes[] = {john,johnny,jackie,johnny,john 
jackie,jamie,jamie,john,johnny,jamie,
johnny,john}
Output: john 4
Explanation: john has 4 votes casted for 
him, but so does johny. john is 
lexicographically smaller, so we print 
john and the votes he received.
Example 2:

Input:
N = 3
Votes[] = {andy,blake,clark}
Output: andy 1
Explanation: All the candidates get 1 
votes each. We print andy as it is 
lexicographically smaller.
Your Task:
You only need to complete the function winner() that takes an array of strings arr, and n as parameters and returns the name of the candiate with maximum votes and the number of votes the candidate got as an array of size 2.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 105
*/


// Code:
// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;

vector<string> winner(string arr[],int n);

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        
        vector<string> result = winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
// } Driver Code Ends


// Funtion to find winner
// arr[]: input array
// n: size of array

vector<string> winner(string arr[],int n)
{
        // map to store count of frequency of each name
        unordered_map<string,int>mp;
        
        
        // storing the frequency of names in the map
        for(int j=0;j<n;j++)
        {
            mp[arr[j]]++;
        }
        
        int maxx=-1;
        string answer="";
        
        // Iterating through the map to find the name with highest frequency
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>maxx)
            {
                maxx=it->second;
                answer=it->first;
            }
            else if(it->second == maxx && answer.compare(it->first) > 0)
                answer = it->first;
        }
        vector<string> vec = {answer,to_string(maxx)};
        return vec;
}