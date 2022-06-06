class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        def helper(nums, N):
            if N == 1: return nums[0]
            else:
                for i in range(N // 2):
                    nums[i] = max(nums[2 * i], nums[2 * i + 1])  if (i % 2 == 1) else min(nums[2 * i], nums[2 * i + 1])
                return helper(nums, N // 2);
        return helper(nums, len(nums))