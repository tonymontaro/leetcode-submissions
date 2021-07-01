// https://leetcode.com/problems/sum-of-even-numbers-after-queries

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int res = 0;
        vector<int> ans; ans.reserve(nums.size());
        for (auto x: nums) if (x %  2 == 0) res += x;
        for (auto& q: queries) {
            int toAdd = q[0], idx = q[1];
            if (nums[idx] % 2  == 0) res -= nums[idx];
            nums[idx] += toAdd;
            if (nums[idx] % 2 == 0) res += nums[idx];
            ans.push_back(res);
        }
        return ans;
    }
};
