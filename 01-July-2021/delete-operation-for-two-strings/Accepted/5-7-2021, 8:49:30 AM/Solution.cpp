// https://leetcode.com/problems/delete-operation-for-two-strings

class Solution {
public:
    int minDistance(string w1, string w2) {
        int n = w1.size(), m = w2.size();
        vector<int> prev(n + 1);
        prev[0] = 0;
        for (int i = 1; i < n + 1; i++) prev[i] = 1 + prev[i - 1];
        for (int i = 0; i < m; i++) {
            vector<int> dp(n + 1);
            dp[0] = prev[0] + 1;
            for (int j = 1; j < n + 1; ++j) {
                if (w2[i] == w1[j-1]) dp[j] = prev[j - 1];
                else dp[j] = 1 + min(prev[j], dp[j - 1]);
            }
            prev = dp;
        }
        return prev[prev.size() - 1];
    }
};