// https://leetcode.com/problems/surface-area-of-3d-shapes

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int rlen = grid.size(), clen = grid[0].size();
        vector<int> rows(rlen);
        vector<int> cols(clen);
        int ans = 0;
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                int val = grid[r][c];
                if (val > 0) ans += 2;
                ans += r > 0 ? max(0, val - grid[r-1][c]) : val;
                ans += r < rlen - 1 ? max(0, val - grid[r + 1][c]) : val;
                ans += c > 0 ? max(0, val - grid[r][c - 1]) : val;
                ans += c < clen - 1 ? max(0, val - grid[r][c + 1]) : val;
            }
        }
        return ans;
    }
};
