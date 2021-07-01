// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<>());
        int change = 0;
        int prev = nums[0] == 0 ? 1 : 0;
        for (auto &x: nums) {
            if (x != prev) change++;
            if (change == 3) return x;
            prev = x;
        }
        return nums[0];
    }
};