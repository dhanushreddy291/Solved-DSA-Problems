class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        N = len(nums)
        LDS = [1] * N
        nums.sort()
        hash = [-1] * N
        for i in range(1, N):
            for j in range(i):
                if nums[i] % nums[j] == 0 and LDS[i] < 1 + LDS[j]:
                    LDS[i] = 1 + LDS[j]
                    hash[i] = j
        maxIndex = LDS.index(max(LDS))
        largestSubset = []
        while maxIndex != -1:
            largestSubset.append(nums[maxIndex])
            maxIndex = hash[maxIndex]
        return largestSubset
