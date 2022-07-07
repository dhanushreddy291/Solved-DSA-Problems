class Solution:
    
    def gameOfLife(self, board: List[List[int]]) -> None:
        N, M = len(board), len(board[0])
        for i in range(N):
            for j in range(M):
                count = self.countOfOnes(i, j, N, M, board)
                if board[i][j] == 0:
                    if count == 3:
                        board[i][j] = 2
                else:
                    if count == 3 or count == 4:
                        board[i][j] = 3
        
        for i in range(N):
            for j in range(M):
                board[i][j] = board[i][j] // 2

    def countOfOnes(self, i, j, N, M, board):
        count = 0
        for dx in range(-1, 2):
            for dy in range(-1, 2):
                if self.isValidPos(i + dx, j + dy, N, M):
                    if board[i + dx][j + dy] % 2 == 1:
                        count += 1
        return count

    def isValidPos(self, x, y, X, Y):
        return x >= 0 and y >= 0 and x < X and y < Y
        