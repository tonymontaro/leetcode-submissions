// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum

#define pi pair<int, int>

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0, n = nums.size();
        vector<pi> seen;
        for (int i = 0; i < nums.size(); i++) {
            int idx = i;
            while (!seen.empty() && nums[i] >= seen.back().first) {
                idx = seen.back().second;
                seen.pop_back();
            }
            if (left <= nums[i] && nums[i] <= right) ans += i - idx + 1;
            seen.emplace_back(nums[i], idx);
        }
        seen.clear();
        for (int i = n - 1; i >= 0; --i) {
            int idx = i;
            while (!seen.empty() && nums[i] > seen.back().first) {
                idx = seen.back().second;
                seen.pop_back();
            }
            if (left <= nums[i] && nums[i] <= right) ans += idx - i;
            seen.emplace_back(nums[i], idx);
        } 
        return ans;
    }
};