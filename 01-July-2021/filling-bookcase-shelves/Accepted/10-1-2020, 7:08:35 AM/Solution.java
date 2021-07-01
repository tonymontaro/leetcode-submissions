// https://leetcode.com/problems/filling-bookcase-shelves

class Solution {
    int[][] books;
    int width;
    int n;
    Integer[] dp;
    public int minHeightShelves(int[][] books, int shelf_width) {
        this.books = books;
        width = shelf_width;
        n = books.length;
        dp = new Integer[n + 1];
        return solve(0);
    }

    int solve(int idx) {
        if (idx >= n) return 0;
        if (dp[idx] == null) {
            int w = books[idx][0];
            int h = books[idx][1];
            int best = h + solve(idx + 1);
            for (int i = idx + 1; i < n; i++) {
                w += books[i][0];
                if (w > width) break;
                h = Math.max(h, books[i][1]);
                best = Math.min(best, h + solve(i + 1));
            }
            dp[idx] = best;
        }
        return dp[idx];
    }
}