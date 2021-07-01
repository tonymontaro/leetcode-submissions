// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum

#define pi pair<int, int>

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0, n = nums.size(), remove = 0;
        vector<pi> seen;
        vector<int> l(n);
        vector<int> r(n);
        for (int i = 0; i < nums.size(); i++) {
            int idx = i;
            while (!seen.empty() && nums[i] >= seen.back().first) {
                idx = seen.back().second;
                seen.pop_back();
            }
            l[i] = idx;
            seen.emplace_back(nums[i], idx);
        }
        seen.clear();
        for (int i = n - 1; i >= 0; --i) {
            int idx = i;
            int le = i - l[i] + 1;
            while (!seen.empty() && nums[i] >= nums[seen.back().first]) {
                int j = seen.back().first;
                if (nums[i] == nums[j]) remove += le * (r[j] - j + 1);
                idx = seen.back().second;
                seen.pop_back();
            }
            r[i] = idx;
            if (left <= nums[i] && nums[i] <= right) ans += (idx - i + 1) * le;
            seen.emplace_back(i, idx);
        }
        return ans - remove;
    }
};