// https://leetcode.com/problems/height-checker

#define v vector


class Solution {
public:
    int heightChecker(vector<int>& heights) {
        v<int> sorted(heights.begin(), heights.end());
        sort(sorted.begin(), sorted.end());
        int ans = 0;
        for (int i = 0; i < sorted.size(); i++) {
            if (sorted[i] != heights[i]) ans++;
        } 
        return ans;
    }
};