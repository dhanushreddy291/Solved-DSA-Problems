class Solution:
    def numOfWays(self, n: int) -> int:
        rep, norm = 6, 6
        for i in range(n - 1):
            rep, norm = 3 * rep + 2 * norm, 2 * rep + 2 * norm
            rep = rep % 1000000007
            norm = norm % 1000000007
        return (rep + norm) % 1000000007
