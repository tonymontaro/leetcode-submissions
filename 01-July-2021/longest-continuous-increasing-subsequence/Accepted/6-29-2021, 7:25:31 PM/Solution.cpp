// https://leetcode.com/problems/longest-continuous-increasing-subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0; int c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] <= nums[i-1]) {
                c = 0;
            }
            c++;
            if (c > ans) ans = c;
        }
        return ans;
    }
};