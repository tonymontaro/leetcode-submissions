// https://leetcode.com/problems/non-decreasing-array

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector<int> nums2(nums.begin(), nums.end());
        return fixLows(nums) || fixHighs(nums2);
    }
    bool fixLows(vector<int> &nums) {
        bool fixed = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                if (fixed) return false;
                fixed = true;
                nums[i] = nums[i - 1];
            }
        } 
        return true;
    }
    bool fixHighs(vector<int> &nums) {
        bool fixed = false;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i+1]) {
                if (fixed) return false;
                fixed = true;
                nums[i] = nums[i + 1];
                if (i > 0 && nums[i-1] > nums[i]) return false;
            }
        } 
        return true;
    }
};