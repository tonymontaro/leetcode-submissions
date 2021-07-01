// https://leetcode.com/problems/lonely-pixel-ii

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& grid, int k) {
        int rlen = grid.size(), clen = grid[0].size();
        map<string, int> row;
        map<int, int> col;
        for (int r = 0; r < rlen; r++) {
            int cnt = 0;
            string rs = "";
            for (int c = 0; c < clen; c++) {
                rs += grid[r][c];
                if (grid[r][c] == 'W') continue;
                cnt++;
                col[c]++;
            }
            if (cnt == k) row[rs]++;
        }
        int ans = 0;
        for (auto [line, cnt]: row) {
            if (cnt != k) continue;
            for (int c = 0; c < clen; c++) 
                if (line[c] == 'B' && col[c] == k) ans += k;
        }
        return ans;
    }
};