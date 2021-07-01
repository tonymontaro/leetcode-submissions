// https://leetcode.com/problems/lucky-numbers-in-a-matrix

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& grid) {
        int rlen = grid.size(), clen = grid[0].size();
        int rows[50] = {0};
        int cols[50] = {0};

        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                int val = grid[r][c];
                if (val > cols[c]) cols[c] = val;
                if (rows[r] == 0 || val < rows[r]) rows[r] = val;
            }
        }
        vector<int> ans;
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                int val = grid[r][c];
                if (rows[r] == val && cols[c] == val) ans.push_back(val);
            }
        }
        return ans;
    }
};