// https://leetcode.com/problems/combination-sum-iv

#define ll long long

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        ll dp[target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < target + 1; i++) {
            for (auto coin: nums) {
                if (coin > i) break;
                dp[i] += dp[i - coin];
            }
        }
        return dp[target];
    }
};
