// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rlen = grid.size(), clen = grid[0].size();
        if (grid[0][0] == 1 || grid[rlen-1][clen-1] == 1) return 0;
        int dp[clen];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                if (grid[r][c] == 1) {
                    dp[c] = 0;
                    continue;
                }
                if (c > 0)
                    dp[c] = dp[c - 1] + dp[c];
            }
        }
        return dp[clen - 1];
    }
};