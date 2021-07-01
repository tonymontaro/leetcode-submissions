// https://leetcode.com/problems/longest-consecutive-sequence

#define umap unordered_map

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        umap<int, int> seen;
        int ans = 0;
        for (auto& x: nums) seen[x] = 1;
        for (auto& x: seen) {
            if (!seen[x.first]) continue;
            int left = x.first;
            while (seen[left]) seen[left--] = 0;
            int right = x.first + 1;
            while(seen[right]) seen[right++] = 0;
            ans = max(ans, right - left - 1);
        }
        return ans;
    }
};