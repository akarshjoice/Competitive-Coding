// Question:
/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

// Code:
#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
      
        sort(a.begin(),a.end());
        int n = a.size();
        int sum;
        int j,k;
        vector<vector<int>> res;
        map<vector<int>, int> mp;
        for(int i = 0;i<n;i++) {
            j=i+1;
            k=n-1;
            while(j<k) {
               sum=a[i] + a[j] + a[k];
               if(sum == 0) {
                  
                   
                   if(mp.count({a[i],a[j],a[k]}) == 0) {
                        res.push_back({a[i],a[j],a[k]});
                        mp.insert({{a[i],a[j],a[k]},1});
                   }
                   j++;
                   k--;
                   continue;
               } else if(sum>0) {
                   k--;
               } else {
                   j++;
               }               
            }
        }
        return res;
    }  
    };