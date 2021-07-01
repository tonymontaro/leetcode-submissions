// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0) return 0;
        
        int minPrice = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.length; i++) {
            minPrice = Math.min(minPrice, prices[i]);
            ans = Math.max(ans, prices[i] - minPrice);
        }
        return ans;
    }
}