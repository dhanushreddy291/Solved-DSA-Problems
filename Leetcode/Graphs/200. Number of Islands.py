class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ds, N, M, islands = [-1, 1, 0, 0], len(grid), len(grid[0]), 0
        def DFS(i, j, N, M, grid):
            if i > -1 and j > -1 and i < N and j < M:
                if grid[i][j] == '1':
                    grid[i][j] = '0'
                    for k in range(4):
                        DFS(i + ds[k], j + ds[3 - k], N, M, grid)
                    return 1
            return 0
        for i in range(N):
            for j in range(M):
                islands += DFS(i, j, N, M, grid)
        return islands