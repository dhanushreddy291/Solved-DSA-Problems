import queue

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        def isValidPos(x, y, X, Y):
            return x >= 0 and x < X and y >= 0 and y < Y
        Queue = queue.LifoQueue()
        Queue.put((sr, sc))
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        Visited = [[False for i in range(len(image[0]))] for j in range(len(image))]
        Visited[sr][sc] = True
        while Queue.qsize() > 0:
            (x, y) = Queue.get()
            for i in range(4):
                if isValidPos(x + dx[i], y + dy[i], len(image), len(image[0])):
                    if not Visited[x + dx[i]][y + dy[i]]:
                        if image[sr][sc] == image[x + dx[i]][y + dy[i]]:
                            Visited[x + dx[i]][y + dy[i]] = True
                            Queue.put((x + dx[i], y + dy[i]))
                            image[x + dx[i]][y + dy[i]] = newColor
        image[sr][sc] = newColor
        return image