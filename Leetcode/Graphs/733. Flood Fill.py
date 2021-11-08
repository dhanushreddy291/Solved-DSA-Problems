import queue

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        def isValidPos(x, y, X, Y):
            return x >= 0 and x < X and y >= 0 and y < Y
        Queue = queue.LifoQueue()
        Queue.put((sr, sc))
        ds = [-1, 1, 0, 0]
        Visited = [[False for i in range(len(image[0]))] for j in range(len(image))]
        Visited[sr][sc] = True
        while Queue.qsize() > 0:
            (x, y) = Queue.get()
            for i in range(4):
                if isValidPos(x + ds[i], y + ds[3 - i], len(image), len(image[0])):
                    if not Visited[x + ds[i]][y + ds[3 - i]]:
                        if image[sr][sc] == image[x + ds[i]][y + ds[3 - i]]:
                            Visited[x + ds[i]][y + ds[3 - i]] = True
                            Queue.put((x + ds[i], y + ds[3 - i]))
                            image[x + ds[i]][y + ds[3 - i]] = newColor
        image[sr][sc] = newColor
        return image