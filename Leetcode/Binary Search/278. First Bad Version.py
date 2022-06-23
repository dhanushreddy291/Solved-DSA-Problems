# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        lo, hi = 1, n
        while lo < hi:
            if isBadVersion((lo + hi) // 2):
                hi = (lo + hi) // 2
            else:
                lo = (lo + hi) // 2 + 1
        return hi