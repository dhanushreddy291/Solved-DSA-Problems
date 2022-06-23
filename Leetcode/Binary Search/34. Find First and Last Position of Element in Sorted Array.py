class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        def findStarting(nums, n):
            N = len(nums)
            lo, hi = 0, N - 1
            while lo <= hi:
                mid = (lo + hi) // 2
                if nums[mid] >= n: hi = mid - 1
                else: lo = mid + 1
            return lo if lo < len(nums) and nums[lo] == target else -1

        def findEnding(nums, n):
            N = len(nums)
            lo, hi = 0, N - 1
            while lo <= hi:
                mid = (lo + hi) // 2
                if nums[mid] <= n: lo = mid + 1
                else: hi = mid - 1
            return hi if nums[hi] == target else -1

        return [findStarting(nums, target), findEnding(nums, target)] if len(nums) > 0 else [-1, -1]