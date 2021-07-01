// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
    static int minFallingPathSum(int[][] grid) {
        int rowLen = grid.length;
        int colLen = grid[0].length;
        if (colLen == 0) return 0;

        for (int row = 1; row < rowLen; row++) {
            for (int col = 0; col < colLen; col++) {
                int prev = grid[row-1][col];
                if (col > 0) prev = Math.min(prev, grid[row-1][col-1]);
                if (col < colLen-1) prev = Math.min(prev, grid[row-1][col+1]);
                grid[row][col] += prev;
            }
        }
        int minVal = grid[rowLen - 1][0];
        for (int num: grid[rowLen - 1]) if (num < minVal) minVal = num;
        return minVal;
    }
}