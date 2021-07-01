// https://leetcode.com/problems/non-decreasing-array

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool fixed = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                if (fixed) return false;
                fixed = true;
                if (i <= 1 || nums[i] >= nums[i-2]) continue;
                else nums[i] = nums[i - 1];
            }
        } 
        return true;
    }
};