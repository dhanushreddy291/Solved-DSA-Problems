class Solution:
    def countSubstrings(self, s: str) -> int:
        N = len(s)
        palindromes = 0
        isPalindrome = [[0] * N for _ in range(N)]
        for length in range(1, N + 1):
            i = 0
            for j in range(i + length - 1, N):
                if (length == 1) or (length == 2 and s[i] == s[j]):
                    isPalindrome[i][j] = 1
                else:
                    isPalindrome[i][j] = 1 if s[i] == s[j] and isPalindrome[i + 1][j - 1] else 0
                palindromes += isPalindrome[i][j]
                i += 1
        return palindromes
