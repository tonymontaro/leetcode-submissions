// https://leetcode.com/problems/triangle


class Solution {
public:
    int prev[201];
    int dp[201];
    int minimumTotal(vector<vector<int>>& triangle) {
        prev[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < i + 1; j++) {
                dp[j] = INT_MAX;
                if (j > 0)
                    dp[j] = triangle[i][j] + prev[j-1];
                if (j < i)
                    dp[j] = min(dp[j], triangle[i][j] + prev[j]);
            }
            for (int j = 0; j < i + 1; j++) prev[j] = dp[j];
        }
        int best = INT_MAX;
        for (int i = 0; i < triangle.size(); i++) best = min(best, prev[i]);
        return best;
    }
};