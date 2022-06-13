class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        return sum([mat[int(i)][i] + mat[len(mat)-i-1][i] for i in range(len(mat))]) - (len(mat) % 2) * mat[len(mat)//2][len(mat)//2]
