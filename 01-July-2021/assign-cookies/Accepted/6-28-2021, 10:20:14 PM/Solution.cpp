// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, ans = 0;
        while (i < g.size() && j < s.size()) {
            while(j < s.size() && g[i] > s[j]) j++;
            if (j >= s.size()) break;
            ans++;
            i++; j++;
        }
        return ans;
    }
};