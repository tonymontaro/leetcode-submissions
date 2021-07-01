// https://leetcode.com/problems/positions-of-large-groups

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        char prev = '*'; int left = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != prev) {
                if (i - left >= 3) ans.push_back({left, i-1});
                left = i;
            }
            prev = s[i];
        }
        int l = s.size() - 1;
        if (s.size() - left >= 3) ans.push_back({left, l});
        return ans;
    }
};