class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        def DFS(i, j, N, M, grid):
            if i > -1 and j > -1 and i < N and j < M:
                if grid[i][j] == 1:
                    islands = 1
                    grid[i][j] = 0
                    for k in range(4):
                        islands += DFS(i + ds[k], j + ds[3 - k], N, M, grid)
                    return islands
            return 0
        
        N, M, islands = len(grid), len(grid[0]), 0

        for i in range(N):
            for j in range(M):
                islands += DFS(i, j, N, M, grid)

        return islands