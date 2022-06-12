class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        start, end, currSum, maxSum, N, Set = 0, 0, 0, 0, len(nums), set()
        while end < N and start <= end:
            if nums[end] in Set:
                while nums[start] != nums[end]:
                    currSum -= nums[start]
                    Set.remove(nums[start])
                    start += 1
                start += 1
            else:
                currSum += nums[end]
                maxSum = max(maxSum, currSum)
                Set.add(nums[end])
            end += 1
        return maxSum