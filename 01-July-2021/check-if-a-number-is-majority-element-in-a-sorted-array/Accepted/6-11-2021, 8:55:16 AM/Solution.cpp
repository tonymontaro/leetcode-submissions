// https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        auto ub = upper_bound(nums.begin(), nums.end(), target);
        
        return ub - lb > nums.size() / 2;
    }
};