// https://leetcode.com/problems/longest-consecutive-sequence

#define umap unordered_map

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        umap<int, int> seen;
        vector<int> seenset;
        
        int ans = 0;
        for (auto& x: nums) {
            if (!seen[x]) {
                seenset.push_back(x);
                seen[x] = 1;
            }
        }
        for (auto& x: seenset) {
            if (!seen[x]) continue;
            int left = x;
            while (seen[left]) seen[left--] = 0;
            int right = x + 1;
            while(seen[right]) seen[right++] = 0;
            ans = max(ans, right - left - 1);
        }
        return ans;
    }
};