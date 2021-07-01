// https://leetcode.com/problems/toeplitz-matrix

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        map<int, int> seen;
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                int val = matrix[r][c];
                if (seen.find(r - c) == seen.end()) {
                    seen[r - c] = val; continue;
                }
                if (val != seen[r - c]) return false;
            }
        }
        return true;
    }
};
