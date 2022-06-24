class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows, columns = len(matrix), len(matrix[0])
        start, end = 1, row * columns

        def coordinatesFindKaro(N, M, Val):
            return (Val / M, Val % M)

        while start <= end:
            mid = (start + end) // 2
            (x, y) = coordinatesFindKaro(rows, columns, mid)
            if matrix[x][y] == target: return True
            elif matrix[x][y] > target: end = mid - 1
            else: end = mid + 1
        return False