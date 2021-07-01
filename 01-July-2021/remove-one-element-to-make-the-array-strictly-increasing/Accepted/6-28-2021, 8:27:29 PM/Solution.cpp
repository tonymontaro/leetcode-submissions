// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int prev = nums[0];
        bool removed = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > prev) {
                prev = nums[i]; continue;
            }
            if (removed) return false;
            if (i == 1 || nums[i] > nums[i-2]) prev = nums[i];
            removed = true;
        }
        return true;
    }
};