class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        N, M = len(mat), len(mat[0])

        def findSoldiers(arr, start, end):
            while start <= end:
                mid = (start + end) // 2
                if arr[mid] == 0:
                    end = mid - 1
                else:
                    start = mid + 1
            return end + 1

        for i in range(N):
            mat[i][0] = findSoldiers(mat[i], 0, M - 1)
        return [item[1] for item in sorted([(mat[i][0], i) for i in range(N)])[ : k]]