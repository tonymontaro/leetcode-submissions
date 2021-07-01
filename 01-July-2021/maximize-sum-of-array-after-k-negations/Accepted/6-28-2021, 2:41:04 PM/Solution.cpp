// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (k == 0 || nums[i] >= 0) break;
            nums[i] = -nums[i];
            k--;
        }
        if (k % 2 == 1) {
            sort(nums.begin(), nums.end());
            nums[0] = -nums[0];
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};