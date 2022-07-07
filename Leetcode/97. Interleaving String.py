class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) == len(s3):
            self.Interleave = [[0]*(len(s2) + 1) for i in range(len(s1)+1)]
            return self.helper(s1, s2, s3, 0, 0, 0) == 1
        return False
    def helper(self, s1: str, s2: str, s3: str, i: int, j: int, k: int) -> bool:
        if self.Interleave[i][j] != 0: return self.Interleave[i][j]
        self.Interleave[i][j] = 1 if (i == len(s1) and j == len(s2) and k == len(s3)) or (i < len(s1) and s1[i] == s3[k] and self.helper(s1, s2, s3, i + 1, j, k + 1) == 1) or (j < len(s2) and s2[j] == s3[k] and self.helper(s1, s2, s3, i, j + 1, k + 1) == 1) else -1
        return self.Interleave[i][j]
