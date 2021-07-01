// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int rows[51] = {0};
        int cols[51] = {0};
        for (auto& x: indices) {
            rows[x[0]]++;
            cols[x[1]]++;
        }
        int ans = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if ((rows[r] + cols[c]) % 2 == 1) ans++;
            }
        }
        return ans;
    }
};