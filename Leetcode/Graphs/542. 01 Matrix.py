import queue
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        
        N, M, Queue, dS = len(mat), len(mat[0]), queue.Queue(), [-1, 1, 0, 0]
        Visited = [[False] * M for x in range(N)]

        def isValidPos(x, y, X, Y):
            return x >= 0 and y >= 0 and x < X and y < Y

        for i in range(N):
            for j in range(M):
                if mat[i][j] == 0:
                    Queue.put((i, j))
                    Visited[i][j] = True
                else:
                    mat[i][j] = 100000

        while Queue.qsize() > 0:
            (x, y) = Queue.get()
            for k in range(4):
                if isValidPos(x + dS[k], y + dS[3 - k], N, M):
                    if not Visited[x + dS[k]][y + dS[3 - k]]:
                        Queue.put((x + dS[k], y + dS[3 - k]))
                        Visited[x + dS[k]][y + dS[3 - k]] = True
                        mat[x + dS[k]][y + dS[3 - k]] = min(1 + mat[x][y], mat[x + dS[k]][y + dS[3 - k]])
        
        return mat