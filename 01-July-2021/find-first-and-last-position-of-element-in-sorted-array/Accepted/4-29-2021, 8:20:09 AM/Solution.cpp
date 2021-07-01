// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto l = lower_bound(nums.begin(), nums.end(), target);
        if (l == nums.end() || *l != target) return {-1, -1};
        auto h = upper_bound(nums.begin(), nums.end(), target);
        int a = l - nums.begin();
        int b = (h - 1) - nums.begin();
        return {a, b};
    }
};
