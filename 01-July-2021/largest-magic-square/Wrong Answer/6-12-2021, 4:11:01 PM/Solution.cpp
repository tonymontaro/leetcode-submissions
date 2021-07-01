// https://leetcode.com/problems/largest-magic-square

#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector
#define ll long long

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans = 1;
        int rlen = grid.size(), clen = grid[0].size();
        v<v<int>> rows(51, v<int>(51));
        v<v<int>> cols(51, v<int>(51));
        for (int r = 0; r < rlen; r++) {
            for (int c = 0; c < clen; c++) {
                rows[c][r + 1] = rows[c][r] + grid[r][c];
                cols[r][c + 1] = cols[r][c] + grid[r][c];
            }
        } 
        for (int i = 2; i < min(rlen, clen) + 1; i++) {
            for (int r = 0; r < rlen - i + 1; r++) {
                for (int c = 0; c < clen - i + 1; c++) {
                    if (validate(grid, rows, cols, r, c, i)) {
                        ans = i;
                        break;
                    }
                }
            }
        } 
        return ans;
    }
    bool validate(v<v<int>>& grid, v<v<int>> &rows, v<v<int>> &cols, int row, int col, int n) {

        int df = rows[col][row + n] - rows[col][row];
        int r1 = 0, r2 = 0;
        for (int i = 0; i < n; i++) {
            r1 += grid[row + i][col + i];
            r2 += grid[row + i][col + n - 1];
            if (rows[col + i][row + n] - rows[col + i][row] != df) return false;
            if (cols[row + i][col + n] - cols[row + i][col] != df) return false;
        } 
        return r1 == df && r2 == df;
    }
};
