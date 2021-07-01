// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int clen = grid[0].size();
        int c = clen - 1, ans = 0;
        for (int r = 0; r < grid.size(); r++) {
            while (c >= 0 && grid[r][c] < 0) c--;
            ans += clen - c - 1;
        } 
        return ans;
    }
};