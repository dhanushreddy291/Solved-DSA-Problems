class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        self.N, self.M, self.longestPath, self.dS = len(grid), len(grid[0]), 0, [-1, 1, 0, 0]
        self.path = [[0] * self.M for i in range(self.N)]
        for i in range(self.N):
            for j in range(self.M):
                self.DFS(i, j, grid)
        return self.longestPath

    def DFS(self, i, j, grid):
        if self.path[i][j] == 0:
            pathCount = 0
            for k in range(4):
                x, y = i + self.dS[k], j + self.dS[3 - k]
                if self.isValidPos(x, y) and grid[x][y] > grid[i][j]:
                    pathCount += self.DFS(x, y, grid)
            self.path[i][j] = 1 + maxPath
        return self.path[i][j]

    def isValidPos(self, i, j):
        return i >= 0 and j >= 0 and i < self.N and j < self.M