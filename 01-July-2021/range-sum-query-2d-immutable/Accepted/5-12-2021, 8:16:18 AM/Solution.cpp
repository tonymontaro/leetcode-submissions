// https://leetcode.com/problems/range-sum-query-2d-immutable

class NumMatrix {
public:
    int grid[201][201];
    NumMatrix(vector<vector<int>>& matrix) {
        int rln = matrix.size(), cln = matrix[0].size();
        memset(grid, 0, sizeof(grid));
        for (int r = 0; r < rln; r++) {
            for (int c = 0; c < cln; c++) grid[r + 1][c + 1] += grid[r + 1][c] + matrix[r][c];
            for (int c = 0; c < cln; c++) grid[r + 1][c + 1] += grid[r][c + 1];
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        return grid[r2+1][c2+1] - grid[r2+1][c1] - grid[r1][c2+1] + grid[r1][c1];
    }
};