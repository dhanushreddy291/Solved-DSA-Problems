class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        Min, N, i, profit = prices[0], len(prices), 1, 0
        while i < N:
            if prices[i] < Min:
                Min = prices[i]
            else:
                profit += (prices[i] - Min)
                Min = prices[i]
            i += 1
        return profit