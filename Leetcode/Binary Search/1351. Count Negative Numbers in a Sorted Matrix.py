class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        
        count, N = 0, len(grid)

        def findPositiveIndex(grid, row):
            M = len(grid[row])
            lo, hi = 0, M - 1
            while lo <= hi:
                mid = (lo + hi) // 2
                if grid[row][mid] >= 0:
                    lo = mid + 1
                else:
                    hi = mid - 1
            return M - lo
         
        for i in range(N):
            count += findPositiveIndex(grid, i)
        
        return count