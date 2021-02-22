// Question:

/*
You are given an amount denoted by value. You are also given an array of coins. The array contains the
denominations of the give coins. You need to find the minimum number of coins to make the change for value using the coins of given denominations. Also, keep in mind that you have infinite supply of the coins.

Example 1:

Input:
value = 5
numberOfCoins = 3
coins[] = {3,6,3}
Output: Not Possible
Explanation:We need to make the change for
value = 5 The denominations are {3,6,3}
It is certain that we cannot make 5 using
any of these coins.
Example 2:

Input:
value = 10
numberOfCoins = 4
coins[] = {2 5 3 6}
Output: 2
Explanation:We need to make the change for
value = 10 The denominations are {2,5,3,6}
We can use two 5 coins to make 10. So
minimum coins are 2.
Your Task:
You only need to complete the function minimumNumberOfCoins() that take array of coins, size of array, and value as parameters. You need to return the minimum number of coins required. If it is not possible to make the exact value out of the given coin denominations, return -1 ("Not Possible" will be printed by the driver's code in this case).

Expected Time Complexity: O(number of coins * value).
Expected Auxiliary Space: O(value)

Constraints:
1 <= value <= 103
1 <= numberOfCoins <= 103
1 <= coinsi <= 1000
*/

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Code: DP - Memoization

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//Complete this function

vector <vector<int>> b;
long long minimumNumberOfCoins1(int a[],int n,int val)
{
   if(b[n][val] == -1) {
        if(val == 0) {
            b[n][val] = 0;
        }
        else if(n == 0) {
            b[n][val] = INT_MAX;
        }
        else {
            if(val - a[n-1] >= 0) {
                b[n][val] = min(1+ minimumNumberOfCoins1(a,n,val - a[n-1]), minimumNumberOfCoins1(a,n-1,val));
            } else {
                b[n][val] = minimumNumberOfCoins1(a,n-1,val);
            }
        }
   }
   return b[n][val];
}

long long minimumNumberOfCoins(int a[],int n,int val)
{  b.resize(n+1);
   for (int i = 0; i < n+1; ++i)
     b[i].resize(val+1);
   for(int i=0;i<n+1;i++) {
       for(int j=0;j<val+1;j++) {
           b[i][j] = -1;
       }
   }
   long long int res = minimumNumberOfCoins1(a,n,val);
   if(res == INT_MAX) {
       return -1;
   }
   return res;
}


// { Driver Code Starts.



int main() {
	
	//taking total count of testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking value
	    int value;
	    cin>>value;
	    
	    //taking number of coins
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    //taking value of each coin
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    
	    //calling function minimumNumberOfCoins()
	    int answer=minimumNumberOfCoins(coins,numberOfCoins,value);
	    
	    //printing "Not Possible" if answer is -1
	    //else printing answer
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends


// Code: DP - Tabular

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//Complete this function

      


long long minimumNumberOfCoins(int a[],int n,int val)
{  
    long long b[n+1][val+1];
    for(int i=0;i<=n;i++) {
      for(int j=0;j<=val;j++) {
          b[i][j]=0;
      }
    }
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=val;j++) {
            if(j == 0 || (i==0&&j==0)) {
                b[i][j] = 0;
            }
            else if(i == 0) {
                b[i][j] = INT_MAX;
            }
            else {
                if(j - a[i-1] >= 0) {
                    b[i][j] = min(1+ b[i][j-a[i-1]], b[i-1][j]);
                } else {
                    b[i][j] = b[i-1][j];
                }
            }  
        }
    }
        
   if(b[n][val] == INT_MAX) {
       return -1;
   }
   return b[n][val];
}


// { Driver Code Starts.



int main() {
	
	//taking total count of testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking value
	    int value;
	    cin>>value;
	    
	    //taking number of coins
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    //taking value of each coin
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    
	    //calling function minimumNumberOfCoins()
	    int answer=minimumNumberOfCoins(coins,numberOfCoins,value);
	    
	    //printing "Not Possible" if answer is -1
	    //else printing answer
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends