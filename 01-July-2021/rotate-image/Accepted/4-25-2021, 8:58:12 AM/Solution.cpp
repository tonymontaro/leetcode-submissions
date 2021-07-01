// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int rlen = grid.size(), clen = grid[0].size();
        for (int row = 0; row < rlen / 2; row++) {
            int col = row;
            for (int c = col; c < clen - col - 1; c++) {
                int r = row;
                int prev = grid[r][c];
                for (int i = 0; i < 4; i++) {
                    int newC = rlen - r - 1;
                    int newR = c;
                    int tmp = grid[newR][newC];
                    grid[newR][newC] = prev;
                    prev = tmp;
                    r = newR, c = newC;
                }
            }
        }
    }
};