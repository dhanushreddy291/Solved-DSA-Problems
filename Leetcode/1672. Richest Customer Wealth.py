class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        return max([sum(balance) for balance in accounts])