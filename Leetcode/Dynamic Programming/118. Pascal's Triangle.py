class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascalsTriangle = [[1]]
        for i in range(1, numRows):
            ithRow = pascalsTriangle[-1].copy()
            N = len(ithRow)
            for j in range(1, N):
                ithRow[j] += pascalsTriangle[-1][j - 1]
            ithRow.append(1)
            pascalsTriangle.append(ithRow)
        return pascalsTriangle
