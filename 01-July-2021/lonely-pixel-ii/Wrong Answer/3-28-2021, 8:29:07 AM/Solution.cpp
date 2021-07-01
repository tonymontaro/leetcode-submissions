// https://leetcode.com/problems/lonely-pixel-ii

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& grid, int k) {
        int rlen = grid.size(), clen = grid[0].size();
        map<int, bitset<200>> row;
        map<int, bitset<200>> col;
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                if (grid[r][c] == 'B') {
                    row[r][c] = true;
                    col[c][r] = true;
                }
            }
        }
        int ans = 0;
        for (int c = 0; c < clen; c++) {
            if (col[c].count() != k) continue;
            bool valid = true;
            int cnt = 0;
            int prev = 0;
            for (int r = 0; r < rlen; r++) {
                if (grid[r][c] != 'B') continue;
                if (row[r].count() != k) {
                    valid = false;
                    break;
                }
                cnt++;
                if (cnt == 1) {
                    prev = r;
                    continue;
                }
                if (row[r][c] != row[prev][c]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
//                print2(c, cnt)
                ans += cnt;
            }
        }
        return ans;
    }
};
