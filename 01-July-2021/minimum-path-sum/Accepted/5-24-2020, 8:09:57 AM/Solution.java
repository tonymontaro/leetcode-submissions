// https://leetcode.com/problems/minimum-path-sum

class Solution {
    static int minPathSum(int[][] grid) {
        int rowLen = grid.length;
        int colLen = grid[0].length;
        if (colLen == 0) return 0;
        for (int row = 0; row < rowLen; row++) {
            for (int col = 0; col < colLen; col++) {
                int prev = 0;
                if (col > 0 && row > 0) prev = Math.min(grid[row-1][col], grid[row][col-1]);
                else if (col > 0) prev = grid[row][col-1];
                else if (row > 0) prev = grid[row-1][col];
                grid[row][col] += prev;
            }
        }

        return grid[rowLen-1][colLen-1];
    }
}