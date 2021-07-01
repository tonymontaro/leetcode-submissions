// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int cc = n - 1 - r;
                int rr = c;
                ans[rr][cc] = matrix[r][c];
            }
        }
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                matrix[r][c] = ans[r][c];
            }
        }
    }
};