// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sm = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (left == (sm - left - nums[i])) return i;
            left += nums[i];
        }
        return -1;
    }
};