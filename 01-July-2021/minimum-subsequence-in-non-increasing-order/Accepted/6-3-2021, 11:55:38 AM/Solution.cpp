// https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans;
        int idx = nums.size() - 1, res = 0;
        while (res <= total) {
            ans.push_back(nums[idx]);
            res += nums[idx];
            total -= nums[idx--];
        }
        return ans;
    }
};
