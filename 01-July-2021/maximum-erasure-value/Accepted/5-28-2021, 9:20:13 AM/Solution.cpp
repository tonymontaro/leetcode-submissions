// https://leetcode.com/problems/maximum-erasure-value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int seen[10002];
        memset(seen, 0, sizeof(seen));
        int left = 0, total = 0, ans = 0;
        for (auto x: nums) {
            while (seen[x] == 1) {
                total -= nums[left];
                seen[nums[left++]] = 0;
            }
            total += x;
            seen[x] = 1;
            ans = max(ans, total);
        }
        return ans;
    }
};