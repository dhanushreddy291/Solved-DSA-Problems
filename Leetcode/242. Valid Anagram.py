class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        Freq1, Freq2 = {}, {}
        for c in s: 
            if c in Freq1.keys():
                Freq1[c] += 1
            else:
                Freq1[c] = 1
        for c in t:
            if c in Freq2.keys():
                Freq2[c] += 1
            else:
                Freq2[c] = 1
        return Freq1 == Freq2