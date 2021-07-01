// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = 0;
        if (n % 2 == 1) mid = nums[n / 2];
        else mid = (nums[n/2] + nums[(n/2)-1]) / 2;
        int ans = 0;
        for (auto x: nums) ans += abs(mid - x);
        return ans;
    }
};