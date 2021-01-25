// Question:
/*
Given an array of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.

Example 1:

Input:
N = 5
A[] = {5,5,4,6,4}
Output: 4 4 5 5 6
Explanation: The highest frequency here is
2. Both 5 and 4 have that frequency. Now
since the frequencies are same then 
smallerelement comes first. So 4 4 comes 
firstthen comes 5 5. Finally comes 6.
The output is 4 4 5 5 6.
Example 2:

Input:
N = 5
A[] = {9,9,9,2,5}
Output: 9 9 9 2 5
Explanation: The highest frequency here is
3. The element 9 has the highest frequency
So 9 9 9 comes first. Now both 2 and 5
have same frequency. So we print smaller
element first.
The output is 9 9 9 2 5.
Your Task:

You only need to complete the function sortByFreq that takes arr, and n as parameters and returns the sorted array.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N). 

Constraints:
1 ≤ N ≤ 105
1 ≤ Ai ≤ 105 
*/

// Code:
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> sortByFreq(int arr[],int n);

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    vector<int> v;
	    v = sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

// } Driver Code Ends


//Complete this function
//Return the sorted array
bool sortby(pair<int,int> a, pair <int,int> b)
{
    if(a.second != b.second) {
        return (a.second > b.second);
    } else {
        return (a.first < b.first);
    }
}


vector<int> sortByFreq(int a[],int n)
{   
    unordered_map <int,int> mp;
    for(int i=0;i<n;i++) {
        mp[a[i]]++;
    }
    
    vector <pair<int,int>> v;
    for(auto i:mp) {
        v.push_back({i.first,i.second});
    }
    
    sort(v.begin(),v.end(),sortby);
    
    vector <int> v1;
    for(int i=0;i<v.size();i++) {
        int k = v[i].second;
        while(k--) {
         v1.push_back(v[i].first);
        }
    }
    return v1;
    
    
    
    
}