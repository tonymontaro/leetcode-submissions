// https://leetcode.com/problems/available-captures-for-rook

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& grid) {
        int row = 0, col = 0;
        for (int r = 0; r < 8; r++) for (int c = 0; c < 8; c++) if (grid[r][c] == 'R') {
            row = r; col = c; break;
        }
        int ans = 0;
        for (int r = row + 1; r < 8; r++) if (grid[r][col] != '.') {
            ans += grid[r][col] == 'p' ? 1 : 0; break;
        }
        for (int r = row - 1; r >= 0; r--) if (grid[r][col] != '.') {
            ans += grid[r][col] == 'p' ? 1 : 0; break;
        }
        for (int c = col + 1; c < 8; c++) if (grid[row][c] != '.') {
            ans += grid[row][c] == 'p' ? 1 : 0; break;
        }
        for (int c = col - 1; c >= 0; c--) if (grid[row][c] != '.') {
            ans += grid[row][c] == 'p' ? 1 : 0; break;
        }
        return ans;
    }
};