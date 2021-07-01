// https://leetcode.com/problems/largest-number-at-least-twice-of-others

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int a = -1, b = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (a == -1 || nums[i] > nums[a]) {
                b = a;
                a = i;
            } else if (b == -1 || nums[i] > nums[b]) {
                b = i;
            }
        }
        return (b != -1 && nums[a] < nums[b]*2) ? -1 : a;
    }
};