class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        N, M = len(s), len(p)
        DP = [[False] * (M + 1) for _ in range(N + 1)]
        DP[0][0] = True
        for j in range(1, M + 1):
            for i in range(i + 1):
                if p[j - 1] == '*':
                    DP[i][j] = DP[i][j - 1]
                    if i - 1 >= 0:
                        DP[i][j] = DP[i][j] or DP[i - 1][j]
                elif i >= 0 and p[j - 1] == '?' or p[j - 1] == s[i - 1]:
                    DP[i][j] = DP[i - 1][j - 1]
        return DP[N][M]
