// https://leetcode.com/problems/largest-subarray-length-k

class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int start = n - k;
        for (int i = n - k; i >= 0; --i) {
            if (nums[i] > nums[start]) start = i;
        }
        return {nums.begin() + start, nums.begin() + start + k};
    }
};