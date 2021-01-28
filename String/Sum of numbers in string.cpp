// Question:
/*
Given a string str containing alphanumeric characters. The task is to calculate the sum of all the numbers present in the string.

Example 1:

Input:
str = 1abc23
Output: 24
Explanation: 1 and 23 are numbers in the
string which is added to get the sum as
24.
Example 2:

Input:
str = geeks4geeks
Output: 4
Explanation: 4 is the only number, so the
sum is 4.
Your Task:
The task is to complete the function findSum() which finds and returns the sum of numbers in the string.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= length of the string <= 105
Sum of Numbers <= 105
*/


// Code:

// { Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


 // } Driver Code Ends


// Function to calculate sum of all numbers present
// in a string containing alphanumeric characters
int findSum(string str)
{
	string s = "";
	int sum = 0;
	int flag =0;
    for(int i=0;i<str.length();i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            s = s + str[i];
            flag = 1;
            continue;
        }
        if(flag == 1) {
            sum+= stoi(s);
            s = "";
            flag = 0;
        }
    }
    if(flag == 1) {
            sum+= stoi(s);
            s = "";
            flag = 0;
        }
    
    return sum;
	
}

// { Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    cout << findSum(str);
        cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends