// https://leetcode.com/problems/4sum-ii

class Solution {
    int[] ar;
    int[] br;
    int[] cr;
    int[] dr;
    int n;
    Integer[][][] dp;
    int rs;
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        ar = A; br = B; cr = C; dr = D;
        Arrays.sort(ar);
        Arrays.sort(br);
        Arrays.sort(cr);
        Arrays.sort(dr);
        n = ar.length;
        dp = new Integer[n + 1][n + 1][n + 1];
        solve(0, 0, 0);
        return rs;
    }

    int solve(int a, int b, int c) {
        if (dp[a][b][c] == null) {
            int sum = ar[a] + br[b] + cr[c];
            if (sum + dr[0] > 0) {
                dp[a][b][c] = 0;
            } else {
                int ans = 0;
                for (int i = 0; i < n; i++) {
                    if (sum + dr[i] == 0) ans++;
                    else if (sum + dr[i] > 0)
                        break;
                }
                if (a < n - 1) solve(a + 1, b, c);
                if (b < n - 1) solve(a, b + 1, c);
                if (c < n - 1) solve(a, b, c + 1);
                rs += ans;
                dp[a][b][c] = ans;
            }
        }
        return dp[a][b][c];
    }
}