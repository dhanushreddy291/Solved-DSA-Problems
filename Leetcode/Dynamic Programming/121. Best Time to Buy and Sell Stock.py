class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        Min, profit, N = prices[0], 0, len(prices)
        for i in range(1, N):
            if prices[i] < Min:
                Min = prices[i]
            else:
                profit = max(profit, prices[i] - Min)
        return profit