class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        currCount, totalCount, N = 0, 0, len(nums)
        for i in range(2, N):
            if nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]:
                currCount += 1
                totalCount += currCount
            else:
                currCount = 0
        return totalCount
