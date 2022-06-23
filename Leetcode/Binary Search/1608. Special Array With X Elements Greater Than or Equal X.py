from bisect import bisect_left

class Solution:
    def specialArray(self, nums: List[int]) -> int:
        N = len(nums)
        nums.sort()
        for i in range(N + 1):
            index = bisect_left(nums, i)
            if N - index == i:
                return i
        return -1