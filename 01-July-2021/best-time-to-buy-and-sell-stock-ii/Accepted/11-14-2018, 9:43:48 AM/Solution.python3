// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution(object):
    def maxProfit(self, prices):
        return sum(max(prices[i + 1] - prices[i], 0) for i in range(len(prices) - 1))