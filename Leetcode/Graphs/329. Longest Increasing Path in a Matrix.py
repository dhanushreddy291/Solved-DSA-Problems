class Solution:

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        self.N, self.M, self.longestPath, self.dS = len(matrix), len(matrix[0]), 0, [-1, 1, 0, 0]
        self.path = [[0] * self.M for i in range(self.N)]
        for i in range(self.N):
            for j in range(self.M):
                self.longestPath = max(self.longestPath, self.DFS(i, j, matrix))
        return self.longestPath

    def DFS(self, i, j, matrix):
        if self.path[i][j] == 0:
            maxPath = 0
            for k in range(4):
                x, y = i + self.dS[k], j + self.dS[3 - k]
                if self.isValidPos(x, y) and matrix[x][y] > matrix[i][j]:
                    maxPath = max(maxPath, self.DFS(x, y, matrix))
            self.path[i][j] = 1 + maxPath
        return self.path[i][j]

    def isValidPos(self, i, j):
        return i >= 0 and j >= 0 and i < self.N and j < self.M