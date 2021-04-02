// Question:
/*
Given an unsorted integer array nums, find the smallest missing positive integer.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
 

Constraints:

0 <= nums.length <= 300
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space?
*/

// Code:
class Solution {
public:
    
    int maxl(int a, int b) {
        if(a>b) {
            return a;
        } else {
            return b;
        }
    }
    int firstMissingPositive(vector<int>& a) {     
        int n = a.size();
        int max=INT_MIN;
        int k=4;
        for(int i=0;i<n;i++) {
            if(a[i]>n || a[i]<=0) {
                a[i] = n+k;
                k++;
                max = maxl(max,a[i]);
            }
            max = maxl(max,a[i]);
        }
        max++;
        int flag = 0;
        for(int i=0;i<n;i++) {
            if(a[i]%max <= n ) {
                
                if(a[i]%max == (i+1)) {
                    a[i]*=max;
                    continue;
                }
                
                if((a[(a[i]%max)-1]%max) == (a[i]%max) || (a[(a[i]%max)-1]/max) == (a[i]%max)) {
                    continue;
                }
                a[(a[i]%max)-1]+= (a[i]%max)*max;
            }        
        }
        for(int i=0;i<n;i++) {
            if((a[i]/max)  != (i+1)) {
                return (i+1);
            }
        }
        return (n+1);
    }
}; 