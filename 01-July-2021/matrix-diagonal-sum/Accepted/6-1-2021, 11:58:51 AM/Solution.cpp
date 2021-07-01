// https://leetcode.com/problems/matrix-diagonal-sum

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        for (int i = 0; i < mat.size(); i++) ans += mat[i][i];
        for (int i = 0; i < mat.size(); i++) {
            if (mat.size() - i - 1 == i) continue;
            ans += mat[i][mat.size() - i - 1];
        }
        return ans;
    }
};