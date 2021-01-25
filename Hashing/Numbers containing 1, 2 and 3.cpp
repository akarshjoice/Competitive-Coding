// Question:
/*
Given an array arr[] of N numbers. The task is to print only those numbers whose digits are from set {1,2,3}.

Example 1:

Input:
N = 3
arr[] = {4,6,7}
Output: -1
Explanation: No elements are there in the 
array which contains digits 1, 2 or 3.
Example 2:

Input:
N = 4
arr[] = {1,2,3,4}
Output: 1 2 3
Explanation: 1, 2 and 3 are the only 
elements in the array which conatins 
digits as 1, 2 or 3.
Your Task:
Complete findAll function and marked satisfied number as '1' in the map mp in range 1 to 1000000. If no number is marked as satified number -1 will automatically be printed by the drivers code. The driver code prints the elements in sorted order.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 <= N <= 106
1 <= A[i] <= 106
*/


// Code:
// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++
bool containsDigit(int x) {
        string str = to_string(x);
        int i = 0;
        while(str[i] != '\0') {
            if(str[i] != '1' && str[i] != '2' && str[i] != '3') {
                return false;
            }
            i++;
        }
        return true;
}

map<int,int> mp; // mp hold 1 to those number which consists of only 1, 2, 3 as digits only 
void findAll() {
    for(int i = 1 ; i < 1000000 ; i++) {
        if(containsDigit(i)) {
                mp[i]++;
        }
    }
}

// { Driver Code Starts.


int main()
{   
    findAll(); // find all such numbers whose digits are from set {1,2,3} from 1 to 1000000
    int t;
    cin>>t; 
    
    while(t--)
    {
        int n, flag=0;
        cin>>n; 
        
        int arr[n] ;
        
        for(int i=0;i<n;i++) // insert n elements
            cin >> arr[i]; 
        
        sort(arr,arr+n); // sort them
        
        for(int i = 0 ; i < n ; ++ i ) {
            if(mp[arr[i]]) { // if arr[i] is already there in the map then it satisfied else not 
                cout << arr[i] << " " ;
                flag=1;
            }
        }
        
        if(!flag)
            cout << "-1"; 
            
        cout<<endl;
    }
return 0;
}  // } Driver Code Ends