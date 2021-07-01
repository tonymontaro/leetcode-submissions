// https://leetcode.com/problems/shift-2d-grid

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rlen = grid.size(), clen = grid[0].size();
        int n = rlen * clen;
        vector<vector<int>> ans(rlen, vector<int>(clen));
        for (int r = 0; r < rlen; ++r) {
            for (int c = 0; c < clen; c++) {
                int newIdx = ((r * clen + c) + k) % n;
                ans[newIdx / clen][newIdx % clen] = grid[r][c];
            }
        }
        return ans;
    }
};