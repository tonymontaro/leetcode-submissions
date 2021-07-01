// https://leetcode.com/problems/running-sum-of-1d-array

#define v vector


class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        v<int> presum = {nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            presum.push_back(nums[i] + presum[i - 1]);
        }
        return presum;
    }
};