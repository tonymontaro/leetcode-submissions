// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
    public static int maxProfit(int k, int[] prices) {
        if (prices.length == 0) return 0;
        int n = prices.length;
        int ans = 0;

        int[] dp = new int[n + 1];
        for (int j = 0; j < k; j++) {
            int addP = Integer.MIN_VALUE;
            for (int i = 1; i < n+1; i++) {
                addP = max(addP, dp[i] - prices[i - 1]);
                dp[i] = max(dp[i], prices[i - 1] + addP);
                dp[i] = max(dp[i], dp[i - 1]);
            }
            if (ans == dp[n]) break;
            ans = dp[n];
        }

        return dp[n];
    }
    private static int min(int a, int b) {
        return Math.min(a, b);
    }
    private static int max(int a, int b) {
        return Math.max(a, b);
    }
}