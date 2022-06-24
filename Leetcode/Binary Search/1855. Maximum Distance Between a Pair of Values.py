class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        N, M, maxDist = len(nums1), len(nums2), 0

        def findIndex(arr, start, end, target):
            while start <= end:
                mid = (start + end) // 2
                if arr[mid] < target:
                    end = mid - 1
                else:
                    start = mid + 1
            return end

        for i in range(N):
            index = findIndex(nums2, i, M - 1, nums1[i])
            
            maxDist = max(maxDist, index - i)
        retur maxDist