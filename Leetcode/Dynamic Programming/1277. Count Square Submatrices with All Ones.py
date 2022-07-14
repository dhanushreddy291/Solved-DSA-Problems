class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        N, M, squares = len(matrix), len(matrix[0]), 0
        for i in range(N):
            for j in range(M):
                if i * j * matrix[i][j] > 0:
                    matrix[i][j] += min(matrix[i - 1][j - 1], matrix[i][j - 1], matrix[i - 1][j])
                squares += matrix[i][j]
        return squares
