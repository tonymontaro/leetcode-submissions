// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i=1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) continue;
            ans += nums[i-1] + 1 - nums[i];
            nums[i] = nums[i-1] + 1;
        }
        return ans;
    }
};