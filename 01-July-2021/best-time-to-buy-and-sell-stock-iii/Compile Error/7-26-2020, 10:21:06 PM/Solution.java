// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
    public static int maxProfit(int[] prices) {
        if (n == 0) return 0;
        int ans = 0;
        int n = prices.length;
        int[] forward = new int[n + 1];
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            forward[i + 1] = max(forward[i], prices[i] - minPrice);
        }
        ans = forward[n];
//        u.print(forward);
        int maxPrice = prices[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            int p = maxPrice - prices[i];
            ans = max(ans, p + forward[i]);
        }

        return ans;
    }
    private static int min(int a, int b) {
        return Math.min(a, b);
    }
    private static int max(int a, int b) {
        return Math.max(a, b);
    }
}