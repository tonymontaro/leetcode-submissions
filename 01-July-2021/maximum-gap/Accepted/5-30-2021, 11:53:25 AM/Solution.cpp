// https://leetcode.com/problems/maximum-gap

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) ans = max(ans, nums[i] - nums[i - 1]);
        return ans;
    }
};