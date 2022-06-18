class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:

        N, M, closedIslands, ds = len(grid), len(grid[0]), 0, [-1, 1, 0, 0]

        def isValidPos(x, y, X, Y):
            return x >= 0 and y >= 0 and x < X and y < Y

        def DFS(x, y, N, M, grid):
            if isValidPos(x, y, N, M):
                if grid[x][y] == 0:
                    grid[x][y] = 1
                    for i in range(4):
                        DFS(x + ds[i], y + ds[3 - i], N, M, grid)

        for j in range(M):
            DFS(0, j, N, M, grid)
            DFS(N - 1, j, N, M, grid)

        for i in range(1, N - 1):
            DFS(i, 0, N, M, grid)
            DFS(i, M - 1, N, M, grid)
        
        for i in range(1, N - 1):
            for j in range(1, M - 1):
                if grid[i][j] == 0:
                    closedIslands += 1
                    DFS(i, j, N, M, grid)
        
        return closedIslands