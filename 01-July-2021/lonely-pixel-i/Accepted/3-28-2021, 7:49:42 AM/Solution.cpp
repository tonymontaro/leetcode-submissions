// https://leetcode.com/problems/lonely-pixel-i

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& grid) {
        int rlen = grid.size(), clen = grid[0].size();
        map<int, int> row;
        map<int, int> col;
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                if (grid[r][c] == 'B') {
                    row[r]++;
                    col[c]++;
                }
            }
        }
        int ans = 0;
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                if (grid[r][c] == 'B' && row[r] == 1 && col[c] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};