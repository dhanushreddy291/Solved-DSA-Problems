import queue
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        
        def isValidPos(x, y, X, Y):
            return x >= 0 and y >= 0 and x < X and y < Y
        
        N, M, Queue, maxDist, ds = len(grid), len(grid[0]), queue.LifoQueue(), 0, [-1, 1, 0, 0]
        dist = [[201]*M]*N
        Visited = [[False]*M]*N
        
        for i in range(N):
            for j in range(M):
                if grid[i][j] == 1:
                    Queue.put((i, j))
                    dist[i][j] = 0
                    Visited[i][j] = True
        
        while Queue.qsize() > 0:
            (x, y) = Queue.get()
            for k in range(4):
                if isValidPos(x + ds[k], y + ds[3 - k], N, M):
                    dist[x + ds[k]][y + ds[3 - k]] = min(dist[x + ds[k]][y + ds[3 - k]], 1 + dist[x][y])
                    if not Visited[x + ds[k]][y + ds[3 - k]]:
                        Queue.put((x + ds[k], y + ds[3 - k]))
                    Visited[x + ds[k]][y + ds[3 - k]] = True
            maxDist = max(maxDist, dist[x][y])
        
        return maxDist