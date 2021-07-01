// https://leetcode.com/problems/maximum-ascending-subarray-sum

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int prev = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) prev += nums[i];
            else prev = nums[i];
            ans = max(ans, prev);
        } 
        return ans;
    }
};