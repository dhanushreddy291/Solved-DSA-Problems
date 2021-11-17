class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        DP = [[0 for x in range(n)] for y in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0 or j == 0: DP[i][j] = 1
                else: DP[i][j] = DP[i - 1][j] + DP[i][j - 1]
        return DP[m - 1][n - 1]