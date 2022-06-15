class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        freq1 = [0] * 26
        freq2 = [0] * 26
        for c in s:
            freq1[ord(c) - 97] += 1
        for c in t:
            freq2[ord(c) - 97] += 1
        for i in range(26):
            if freq1[i] != freq2[i]:
                return chr(97 + i)