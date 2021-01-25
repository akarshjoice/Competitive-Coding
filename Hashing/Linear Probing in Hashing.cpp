// Question:
/*
Linear probing is a collision handling technique in hashing. Linear probing says that whenever a collision occurs, search for the immediate next position.

Given an array of integers and a hash table size. Fill the array elements into a hash table using Linear Probing to handle collisions.

Example 1:

Input:
hashSize = 10
sizeOfArray = 4 
Array[] = {4,14,24,44}
Output:
-1 -1 -1 -1 4 14 24 44 -1 -1
Explanation: 4%10=4. So put 4 in 
hashtable[4].Now, 14%10=4, but 
hashtable[4] is alreadyfilled so put 
14 in the next slot and so on.
Example 2:

Input:
hashSize = 10
sizeOfArray = 4 
Array[] = {9,99,999,9999}
Output:
99 999 9999 -1 -1 -1 -1 -1 -1 9
Explanation: 9%10=9. So put 9 in 
hashtable[9]. Now, 99%10=9, but 
hashtable[9] is already filled so 
put 99 in the (99+1)%10 =0 slot so
99 goes into hashtable[0] and so on.
Your Task:
You don't need to read input or print anything. Your task is to complete the function linearProbing() which takes as input a empty hash table (hash), the hash table size (hashSize), an integers array arr[] and its size N and inserts all the elements of the array arr[] into the given hash table. The empty cells of the hash table are to be given a value of -1. Also, if there's no more space to insert a new element, just drop that element. 

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(1).

Constraints:
1 <= hashSize <= 100
1 <= sizeOfArray <= 100
0 <= Array[] <= 105
*/


// Code:
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> linearProbing(int hashSize,int arr[],int sizeOfArray);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    
	    int  sizeOfArray;
	    cin>>sizeOfArray;
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    vector<int> hash;
	    
	    hash = linearProbing( hashSize, arr, sizeOfArray);
	    
	    for(int i=0;i<hashSize;i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	    
	}
	return 0;
}

// } Driver Code Ends


//Complete this function

vector<int> linearProbing(int hashSize, int arr[], int N)
{
    vector <int> a(hashSize,-1);
    int sum;
    for(int i=0;i<N;i++) {
        int j=0;
        sum=arr[i]%hashSize;
        int k=sum;
        int flag=0;
        while(a[sum]!=-1) {
            sum=(sum+1)%hashSize;
            if(flag==1 && sum==k) {
                break;
            }
            flag=1;
            
        }
        if(flag==1 && sum==k) {
                continue;
            }
        a[sum]=arr[i];
    }
    return a;
}