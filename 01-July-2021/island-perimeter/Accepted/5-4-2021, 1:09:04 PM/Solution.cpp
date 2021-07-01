// https://leetcode.com/problems/island-perimeter

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rlen = grid.size(), clen = grid[0].size();
        int perimeter = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int row = 0; row < rlen; row++) {
            for (int col = 0; col < clen; col++) {
                if (grid[row][col] == 0) continue;
                for (auto x: dirs) {
                    int r = row + x.first, c = col + x.second;
                    if (r < 0 || r >= rlen || c < 0 || c >= clen || grid[r][c] == 0)
                        perimeter++;
                }
            }
        }
        return perimeter;
    }
};