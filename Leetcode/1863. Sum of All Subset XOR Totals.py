class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        def helper(nums, pos, XOR):
            return XOR if pos == len(nums) else helper(nums, pos + 1, XOR) + helper(nums, pos + 1, XOR ^ nums[pos])
        return helper(nums, 0, 0)