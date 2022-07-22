class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        N, M = len(matrix), len(matrix[0])
        orig = matrix[0][0]
        for i in range(N):
            for j in range(M):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        print(matrix)
        for i in range(1, N):
            for j in range(1, M):
                matrix[i][j] = 0 if matrix[i][0] * matrix[0][j] == 0 else matrix[i][j]
        new = matrix[0][0]
        matrix[0][0] = orig
        if matrix[0][0] == 0:
            matrix[0] = [0] * M
            for i in range(N):
                matrix[i][0] = 0
        matrix[0][0] = new
