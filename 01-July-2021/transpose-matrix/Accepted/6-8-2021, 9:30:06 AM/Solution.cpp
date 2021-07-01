// https://leetcode.com/problems/transpose-matrix

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rlen = matrix.size(), clen = matrix[0].size();
        vector<vector<int>> ans(clen, vector<int>(rlen));
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                ans[c][r] = matrix[r][c];
            }
        }
        return ans;
    }
};