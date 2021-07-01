// https://leetcode.com/problems/projection-area-of-3d-shapes

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int rows[51] = {0};
        int cols[51] = {0};
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                if (val > 0) ans++;
                rows[i] = max(rows[i], val);
                cols[j] = max(cols[j], val);
            }
        }
        for (int i = 0; i < n; i++) ans += rows[i] + cols[i];
        return ans;
    }
};