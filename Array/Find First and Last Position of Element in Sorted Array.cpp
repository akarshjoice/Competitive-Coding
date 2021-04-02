// Question:
/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/
// Code:
class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        
        
        int l = 0;
        int u = a.size() - 1;
        int start =-1;
        int m;
        while(l<=u) {
            m = (l+u)/2;
            if(target > a[m]) {
                l = m+1;
            } else if(target < a[m]) {
                u = m-1;
            } else {
                start = m;
                if(m == 0) {
                    break;
                }
                u=m-1;
            }
        }
        int end=-1;
        l=0;
        u = a.size() -1;
        while(l<=u) {
            m = (l+u)/2;
            if(target > a[m]) {
                l = m+1;
            } else if(target < a[m]) {
                u = m-1;
            } else {
                end = m;
                if(m == a.size()-1) {
                    break;
                }
                l = m+1;
            }
        }
        return {start,end};
    }
};