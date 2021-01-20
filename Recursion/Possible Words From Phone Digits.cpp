// Question:
/*
Given a keypad as shown in the diagram, and an N digit number which is represented by array a[], the task is to list all words which are possible by pressing these numbers.



Example 1:

Input: N = 3, a[] = {2, 3, 4}
Output:
adg adh adi aeg aeh aei afg afh
afi bdg bdh bdi beg beh bei bfg
bfh bfi cdg cdh cdi ceg ceh cei
cfg cfh cfi 
Explanation: When we press 2,3,4 
then adg,adh,adi , ......,cfi are
the list of possible words.
Example 2:

Input: N = 3, a[] = {3, 4, 5}
Output:
dgj dgk dgl dhj dhk dhl dij dik
dil egj egk egl ehj ehk ehl eij 
eik eil fgj fgk fgl fhj fhk fhl 
fij fik fil
Explanation: When we press 3,4,5 
then dgj,dgk,dgl,.......,fil are 
the list of possible words.
Your Task:
You don't need to read input or print anything. You just need to complete the function possibleWords() that takes an array a[] and N as parameters and returns an array of all the possible words in lexicographical order. 

Expected Time Complexity: O(4^N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 10
2 ≤  a[i] ≤ 9
*/




// Code:
// { Driver Code Starts
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector <string> possibleWords(int a[],int n);


int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	  vector <string> res = possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}// } Driver Code Ends


//Complete this function
map <int,int> mp;
map <int,string> mp1;
int fun(int a[],int N, int j,string d,vector <string> &b) 
{   
    if(j == N) {
        b.push_back(d);
        return 0;
    }
    
    for(int i=0;i<mp[a[j]];i++)
    {
        fun(a,N,j+1,d+mp1[a[j]][i],b);
    }
}



vector <string> possibleWords(int a[],int N)
{
    
    mp.insert({2,3});
    mp.insert({3,3});
    mp.insert({4,3});
    mp.insert({5,3});
    mp.insert({6,3});
    mp.insert({7,4});
    mp.insert({8,3});
    mp.insert({9,4});
    
    mp1.insert({2,"abc"});
    mp1.insert({3,"def"});
    mp1.insert({4,"ghi"});
    mp1.insert({5,"jkl"});
    mp1.insert({6,"mno"});
    mp1.insert({7,"pqrs"});
    mp1.insert({8,"tuv"});
    mp1.insert({9,"wxyz"});
    vector <string> b;
    fun(a,N, 0, "",b) ;
    return b;
    
}