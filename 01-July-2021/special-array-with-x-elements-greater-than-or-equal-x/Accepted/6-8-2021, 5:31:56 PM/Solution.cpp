// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0; i < n; ++i) {
            if (nums[i] >= n - i && (i == 0 || nums[i-1] < n - i)) return n - i;
        }
        return -1;
    }
};