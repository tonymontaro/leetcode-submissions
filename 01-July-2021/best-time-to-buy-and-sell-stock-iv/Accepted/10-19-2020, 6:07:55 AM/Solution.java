// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        if (k >= prices.length / 2) {
            int ans = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i-1])
                    ans += prices[i] - prices[i - 1];
            }
            return ans;
        }

        int[] prev = new int[n + 1];
        for (int j = 0; j < k; j++) {
            int[] cur = new int[n + 1];
            int deal = -prices[0];
            for (int i = 2; i < n + 1; i++) {
                int price = prices[i - 1];
                cur[i] = max(prev[i], cur[i - 1], price + deal);
                deal = max(deal, prev[i - 1] - price);
            }
            prev = cur;
        }

        return prev[n];
    }
    
    private static int max(int... ins){ int max = ins[0]; for(int i=1; i<ins.length; i++){ if(ins[i] > max) max = ins[i]; } return max; }
}