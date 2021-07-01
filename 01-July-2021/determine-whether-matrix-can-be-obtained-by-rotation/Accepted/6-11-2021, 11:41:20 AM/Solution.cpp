// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target) return true;
        int n = mat.size();
        vector<vector<int>> vec(n, vector<int>(n));
        for (int i = 0; i < 4; i++) {
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    int col = r;
                    int row = n - c - 1;
                    vec[row][col] = mat[r][c];
                }
            }
            if (vec == target) return true;
            swap(vec, mat);
        }
        return false;
    }
    bool equal(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool ans = true;
        for (int r = 0; r < mat.size(); r++) {
            for (int c = 0; c < mat.size(); c++) {
                if (mat[r][c] != target[r][c]) ans = false;
            }
        }
        return ans;
    }
};