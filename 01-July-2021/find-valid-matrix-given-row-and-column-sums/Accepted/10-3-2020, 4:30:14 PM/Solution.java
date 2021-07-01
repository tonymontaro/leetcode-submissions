// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums

class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int rowlen = rowSum.length, colen = colSum.length;
        int[][] grid = new int[rowlen][colen];
        for (int r = 0; r < rowlen; r++) {
            for (int c = 0; c < colen; c++) {
                int mn = Math.min(rowSum[r], colSum[c]);
                rowSum[r] -= mn;
                colSum[c] -= mn;
                grid[r][c] = mn;
            }
        }
        return grid;
    }
}