class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        HammingDistance = 0;
        while x != 0 or y != 0:
            if (x & 1) ^ (y & 1) == 1: 
                HammingDistance += 1
            x >>= 1
            y >>= 1
        return HammingDistance