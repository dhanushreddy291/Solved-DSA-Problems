class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        N = len(nums)
        Count = [0]*101
        for i in range(N):  Count[nums[i]] += 1
        for i in range(100):  Count[i + 1] += Count[i]
        for i in range(N):
            if nums[i] != 0: 
                nums[i] = Count[nums[i] - 1]
        return nums