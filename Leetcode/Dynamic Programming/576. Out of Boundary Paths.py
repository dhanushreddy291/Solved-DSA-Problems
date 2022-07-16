class Solution:
    def findPathsH(self, m, n, maxMove, i, j):
        if i >= m or i < 0 or j >= n or j < 0:
            return 1
        if maxMove <= 0:
            return 0

        if self.paths[i][j][maxMove] == -1:
            res = (
                self.findPathsH(m, n, maxMove - 1, i + 1, j)
                + self.findPathsH(m, n, maxMove - 1, i - 1, j)
                + self.findPathsH(m, n, maxMove - 1, i, j + 1)
                + self.findPathsH(m, n, maxMove - 1, i, j - 1)
            )
            self.paths[i][j][maxMove] = res % self.mod
            
        return self.paths[i][j][maxMove]

    def findPaths(
        self, m: int, n: int, maxMove: int, startRow: int, startColumn: int
    ) -> int:
        self.mod = 1000000007
        self.paths = [
            [[-1 for _ in range(maxMove + 1)] for _ in range(n)] for _ in range(m)
        ]
        return self.findPathsH(m, n, maxMove, startRow, startColumn) % self.mod
