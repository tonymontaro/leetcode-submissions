// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sm = 0;
        int left = 0;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sm += nums[i];
            while (sm - nums[left] >= target) {
                sm -= nums[left];
                left++;
            }
            if (sm >= target)
                ans = min(ans, i - left + 1);
        } 
        return (ans == INT_MAX) ? 0 : ans;
    }
};