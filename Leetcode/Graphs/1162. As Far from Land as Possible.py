import queue

class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        
        def isValidPos(x, y, X, Y):
            return x >= 0 and y >= 0 and x < X and y < Y
        
        N, M, Queue, maxDist, ds = len(grid), len(grid[0]), queue.Queue(), 0, [-1, 1, 0, 0]
        Visited = [[False for x in range(M)] for x in range(N)]
        
        for i in range(N):
            for j in range(M):
                if grid[i][j] == 1:
                    Queue.put((i, j))
                    grid[i][j] = 0
                    Visited[i][j] = True
                else:
                    grid[i][j] = 201
        
        while Queue.qsize() > 0:
            (x, y) = Queue.get()
            for k in range(4):
                if isValidPos(x + ds[k], y + ds[3 - k], N, M) and not Visited[x + ds[k]][y + ds[3 - k]]:
                    grid[x + ds[k]][y + ds[3 - k]] = min(grid[x + ds[k]][y + ds[3 - k]], 1 +  grid[x][y])
                    Queue.put((x + ds[k], y + ds[3 - k]))
                    Visited[x + ds[k]][y + ds[3 - k]] = True
            maxDist = max(maxDist, grid[x][y])
        
        return -1 if maxDist == 0 else maxDist