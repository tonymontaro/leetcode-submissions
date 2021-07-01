// https://leetcode.com/problems/pascals-triangle-ii

int c[35][35];

class Solution {
public:
    Solution(){ memset(c, 0, sizeof(c)); }
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.reserve(rowIndex + 1);
        for (int i = 0; i < rowIndex + 1; i++) res.push_back(solve(rowIndex, i));
        return res;
    }
    int solve(int row, int i) {
        if (i == 0 || i == row) return 1;
        if (c[row][i]) return c[row][i];
        c[row][i] = solve(row - 1, i - 1) + solve(row - 1, i);
        return c[row][i];
    }
};