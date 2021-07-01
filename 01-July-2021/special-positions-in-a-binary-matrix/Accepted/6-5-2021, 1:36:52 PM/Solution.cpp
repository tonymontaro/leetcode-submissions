// https://leetcode.com/problems/special-positions-in-a-binary-matrix

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows[101] = {0};
        int cols[101] = {0};
        for (int r = 0; r < mat.size(); r++) {
            for (int c = 0; c < mat[0].size(); c++) {
                rows[r] += mat[r][c];
                cols[c] += mat[r][c];
            }
        }
        int ans = 0;
        for (int r = 0; r < mat.size(); r++) {
            for (int c = 0; c < mat[0].size(); c++) {
                if (mat[r][c] && rows[r] == 1 && cols[c] == 1) ans++;
            }
        }
        return ans;
    }
};