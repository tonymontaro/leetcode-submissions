// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
    int rowlen;
    int colen;
    int[][] grid;
    public int kthSmallest(int[][] matrix, int k) {
        grid = matrix;
        rowlen = matrix.length;
        colen = matrix[0].length;
        int lo = matrix[0][0];
        int hi = matrix[rowlen - 1][colen - 1];
        int valid = hi;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int count = countLessOrEqual(mid);
            if (count >= k) {
                valid = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return valid;
    }

    int countLessOrEqual(int num) {
        int ans = 0;
        int r = 0;
        int c = colen - 1;
        while (c >= 0 && r < rowlen) {
            while (c >= 0 && grid[r][c] > num) c--;
            ans += c + 1;
            r += 1;
        }
        return ans;
    }
}