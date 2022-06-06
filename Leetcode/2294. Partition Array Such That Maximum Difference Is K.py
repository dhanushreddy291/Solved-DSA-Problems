class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        if k == 0: return len(set(nums))
        nums.sort()
        partitions, Min, Max = 0, nums[0], nums[0]
        for num in nums:
            Min = min(Min, num)
            Max = max(Max, num)
            if Max - Min > k:
                partitions += 1
                Min = Max = num
        return 1 + partitions