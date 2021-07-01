// https://leetcode.com/problems/lonely-pixel-ii

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& grid, int k) {
        int rlen = grid.size(), clen = grid[0].size();
        map<string, int> rowCount;
        map<int, int> colCount;
        for (int r = 0; r < rlen; r++) {
            string s = "";
            for (int c = 0; c < clen; c++) {
                s += grid[r][c];
                if (grid[r][c] == 'B') colCount[c]++;
            }
            rowCount[s]++;
        }
        int ans = 0;
        for (auto[s, cnt]: rowCount) {
            if (cnt != k) continue;
            for (int c = 0; c < clen; c++) {
                if (s[c] == 'B' && colCount[c] == k) ans += k;
            }
        }
        return ans;
    }
};
