// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
    int rowlen;
    int colen;
    Integer[][] dp;
    int[][] grid;
    int[][] adjacentGrids = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    public int longestIncreasingPath(int[][] matrix) {
        grid = matrix;
        if (matrix.length == 0) return 0;
        rowlen = matrix.length;
        colen = matrix[0].length;
        dp = new Integer[rowlen + 1][colen + 1];
        int ans = 0;
        for (int r = 0; r < rowlen; r++) {
            for (int c = 0; c < colen; c++) ans = Math.max(ans, calc(r, c));
        }
        return ans;
    }
    int calc(int r, int c) {
        if (dp[r][c] == null) {
            int num = grid[r][c];
            int ans = 1;
            for (int[] ag : adjacentGrids) {
                int rr = r + ag[0];
                int cc = c + ag[1];
                if (isInArea(rr, cc) && grid[rr][cc] > num)
                    ans = Math.max(ans, 1 + calc(rr, cc));
            }
            dp[r][c] = ans;
        }
        return dp[r][c];
    }
    boolean isInArea(int r, int c){
        if(r<0) return false;
        if(c<0) return false;
        if(r>=rowlen) return false;
        if(c>=colen) return false;
        return true;
    }
}