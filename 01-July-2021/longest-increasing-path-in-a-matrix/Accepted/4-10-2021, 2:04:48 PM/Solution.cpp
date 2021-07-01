// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

#define pi pair<int, int>
#define v vector


int cache[200][200];
int grid[200][200];

bool compare(pi a, pi b) {
    return grid[a.first][a.second] > grid[b.first][b.second];
}

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(cache, 0, sizeof(cache));
        int rlen = matrix.size(), clen = matrix[0].size();
        v<pi> points;
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                points.push_back({r, c});
                grid[r][c] = matrix[r][c];
            }
        }
        sort(points.begin(), points.end(), compare);
        v<pi> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 0;
        for (auto [row, col]: points) {
            int res = 1;
            int val = grid[row][col];
            for (auto [rAdd, cAdd]: dirs) {
                int r = row + rAdd, c = col + cAdd;
                if (r < 0 || r >= rlen || c < 0 || c >= clen || val >= grid[r][c]) continue;
                res = max(res, 1 + cache[r][c]);
            }
            cache[row][col] = res;
            ans = max(ans, res);
        }

        return ans;
    }
};