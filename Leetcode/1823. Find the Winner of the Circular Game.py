class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        return 1 if n == 1 else 1 + (k - 1 + self.findTheWinner(n - 1, k)) % n
