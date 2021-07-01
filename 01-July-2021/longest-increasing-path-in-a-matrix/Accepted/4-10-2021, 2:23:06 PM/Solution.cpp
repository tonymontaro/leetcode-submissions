// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

#define pi pair<int, int>
#define v vector


class Solution {
public:
    int cache[200][200];
    int rlen, clen;
    v<pi> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(cache, 0, sizeof(cache));
        rlen = matrix.size(), clen = matrix[0].size();
        int ans = 0;
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; ++c) {
                ans = max(ans, solve(r, c, matrix));
            }
        }
        return ans;
    }
    int solve(int row, int col, v<v<int>> &matrix) {
        if (cache[row][col] != 0) return cache[row][col];
        int res = 1;
        int val = matrix[row][col];
        for (auto [rAdd, cAdd]: dirs) {
            int r = row + rAdd, c = col + cAdd;
            if (r < 0 || r >= rlen || c < 0 || c >= clen || val >= matrix[r][c]) continue;
            res = max(res, 1 + solve(r, c, matrix));
        }
        cache[row][col] = res;
        return res;
    }
};
