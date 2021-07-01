// https://leetcode.com/problems/maximum-score-after-splitting-a-string

class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int ones = 0;
        for (auto x: s) if (x == '1') ones++;
        int zeros = 0;
        for (auto x: s) {
            if (x == '0') zeros++;
            else ones--;
            ans = max(ans, ones + zeros);
        }
        return ans;
    }
};