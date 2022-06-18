class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        N, M, subIslands, ds = len(grid1), len(grid1[0]), 0, [-1, 1, 0, 0]
        def isValidPos(x, y, X, Y):
            return x >= 0 and y >= 0 and x < X and y < Y
        def DFS(x, y, X, Y, A, B, valid):
            if isValidPos(x, y, X, Y):
                if B[x][y] == 0: return 0
                B[x][y] = 0
                for k in range(4):
                    DFS(x + ds[k], y + ds[3 - k], X, Y, A, B, valid)
                if A[x][y] == 0:
                    valid[0] = 0
                    return 0
                else:
                    return 1
            else:
                return 0
        for i in range(N):
            for j in range(M):
                if grid2[i][j] == 1:
                    valid = [1]
                    temp = DFS(i, j, N, M, grid1, grid2, valid)
                    if valid[0] == 1:
                        subIslands += temp
        return subIslands 