class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        N, M = len(nums1), len(nums2)
        if M < N: return self.findMedianSortedArrays(nums2, nums1)
        lo, hi, lPos = 0, N, (N + M + 1) // 2
        while lo <= hi:
            mid1 = (lo + hi) // 2
            mid2 = lPos - mid1
            l1 = nums1[mid1 - 1] if mid1 > 0 else -(10**6)
            l2 = nums2[mid2 - 1] if mid2 > 0 else -(10**6)
            r1 = nums1[mid1] if mid1 < N else 10**6
            r2 = nums2[mid2] if mid2 < M else 10**6
            if max(l1, l2) <= min(r1, r2):
                if (N + M) % 2 == 0:
                    return (max(l1, l2) + min(r1, r2)) / 2
                return max(l1, l2)
            elif l1 < r2:
                lo = mid1 + 1
            else:
                hi = mid1 - 1
