// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    int seen[50][50];
    int rlen, clen;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(seen, 0, sizeof(seen));
        rlen = grid.size(); clen = grid[0].size();
        int ans = 0;
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                if (grid[r][c]) ans = max(ans, bfs(r, c, grid));
            }
        } 
        return ans;
    }
    int bfs(int row, int col, vector<vector<int>>& grid) {
        if (row < 0 || row >= rlen || col <  0 || col >= clen || seen[row][col] || !grid[row][col]) return 0;
        int ans = 1;
        seen[row][col] = 1;
        for (auto [rAdd, cAdd]: dirs) ans += bfs(row + rAdd, col + cAdd, grid);
        return ans;
    }
};