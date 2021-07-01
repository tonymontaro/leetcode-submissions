// https://leetcode.com/problems/pacific-atlantic-water-flow

#define v vector

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        v<v<int>> ans;
        if (grid.size() == 0 || grid[0].size() == 0) return ans;
        int rlen = grid.size(), clen = grid[0].size();
        stack<pair<int, int>> pacific;
        stack<pair<int, int>> atlantic;
        int dp[rlen][clen];
        memset(dp, 0, sizeof(dp));
        for (int r = 0; r < rlen; r++) {
            pacific.push({r, 0});
            atlantic.push({r, clen - 1});
            dp[r][0] = 1;
        }
        for (int c = 0; c < clen; c++) {
            pacific.push({0, c});
            atlantic.push({rlen - 1, c});
            dp[0][c] = 1;
        }

        v<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pacific.empty()) {
            auto node = pacific.top();
            pacific.pop();
            int row = node.first, col = node.second;
            int val = grid[row][col];
            for (auto [rAdd, cAdd]: dirs) {
                int r = row + rAdd, c = col + cAdd;
                if (r < 0 || r >= rlen || c < 0 || c >= clen || dp[r][c] > 0) continue;
                if (val > grid[r][c]) continue;
                dp[r][c] = 1;
                pacific.push({r, c});
            }
        }

        while (!atlantic.empty()) {
            auto node = atlantic.top();
            atlantic.pop();
            int row = node.first, col = node.second;
            int val = grid[row][col];
            if (dp[row][col] == 2) continue;
            if (dp[row][col] == 1) ans.push_back({row, col});
            dp[row][col] = 2;
            for (auto [rAdd, cAdd]: dirs) {
                int r = row + rAdd, c = col + cAdd;
                if (r < 0 || r >= rlen || c < 0 || c >= clen || dp[r][c] > 1) continue;
                if (val > grid[r][c]) continue;
                atlantic.push({r, c});
            }
        }
        return ans;
    }
};
