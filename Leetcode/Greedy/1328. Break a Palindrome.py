class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        N = len(palindrome)
        if N == 1:
            return ""
        end = (N // 2)
        if palindrome[0] != 'a':
            return 'a' + palindrome[1:]
        for i in range(end):
            if palindrome[i] != 'a':
                return palindrome[:i] + 'a' + palindrome[i+1:]
        return palindrome[:-1] + 'b'