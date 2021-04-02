// Question:
/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
 

Follow up: Can you achieve this in O(log n) time complexity?
Accepted
955,496
Submissions
2,649,774
*/


// Code:
class Solution {
public:
    
    int binarySearch(vector<int>& a, int target,int start,int end) {
        
        int m;
        cout<<endl;
        while(start<=end) {
            m = (start+end)/2;
            if(target > a[m]) {
                start = m+1;
            } else if(target < a[m]) {
                end = m-1;
            } else {
                return m;
            }
        }
        return -1;
    }
    
    int search(vector<int>& a, int target) {
     
        int l=0,r = a.size()-1;
        int m=0;
        int n = a.size();
        if(a[0] < a[n-1]) {
            return binarySearch(a,target,0,n-1);
        }
        while(l<r)
        {
            int mid=(r+l)/2;
            
            if(a[mid]>a[r])
                l=mid+1;
            else 
                r=mid;
        }
    
        cout<<m<<" ";
        if(a[0] < target) {
            return binarySearch(a,target,0,l-1);
        } else if(a[0] > target){
            return binarySearch(a,target,l,n-1);
        } else {
            return 0;
        }
        
        
        return -1;
    }
};