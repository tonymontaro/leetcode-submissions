// https://leetcode.com/problems/largest-number-at-least-twice-of-others

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[a]) {
                b = a;
                a = i;
            } else if (nums[i] > nums[b]) {
                b = i;
            }
        }
        return (a != b && nums[a] < nums[b]*2) ? -1 : a;
    }
};