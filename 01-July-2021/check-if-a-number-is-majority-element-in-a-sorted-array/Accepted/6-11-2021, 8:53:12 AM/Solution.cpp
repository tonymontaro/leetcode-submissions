// https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int cnt = 0;
        for (auto x: nums) if (x == target) cnt++;
        return cnt > nums.size() / 2;
    }
};