// https://leetcode.com/problems/score-after-flipping-matrix

#define v vector



int colCount[20];
class Solution {
public:
    int rlen, clen;
    int matrixScore(vector<vector<int>>& grid) {
        rlen = grid.size(), clen = grid[0].size();

        memset(colCount, 0, sizeof(colCount));
        for (int r = 0; r < rlen; r++) {
            if (grid[r][0] == 0)
                toggleRow(grid, r);
            for (int c = 0; c < clen; c++) {
                colCount[c] += grid[r][c];
            }
        }
        int half = (rlen + 1) / 2;
        for (int c = 0; c < clen; c++)
            if (colCount[c] < half)
                toggleCol(grid, c);
        int ans = 0;
        for (int r = 0; r < rlen; r++) {
            int num = 0;
            for (int c = 0; c < clen; c++) {
                num = (num << 1) | grid[r][c];
            }
            ans += num;
        }
        return ans;
    }
    void toggleRow(v<v<int>> &grid, int r) {
        for (int c = 0; c < clen; c++) {
            grid[r][c] = (grid[r][c] == 1) ? 0 : 1;
        }
    }
    void toggleCol(v<v<int>> &grid, int c) {
        for (int r = 0; r < rlen; r++) {
            grid[r][c] = (grid[r][c] == 1) ? 0 : 1;
        }
    }
};