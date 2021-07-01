// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
    public static int maxProfit(int[] prices) {
        int n = prices.length;
        if (n == 0) return 0;
        int minPrice = prices[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);

            if ((i < n - 1 && prices[i] > prices[i - 1] && prices[i] >= prices[i + 1]) || (i == n - 1 && prices[i] > prices[i - 1])) {
                ans += prices[i] - minPrice;
                minPrice = Integer.MAX_VALUE;
            }
        }
        return ans;
    }
    private static int min(int a, int b) {
        return Math.min(a, b);
    }
}