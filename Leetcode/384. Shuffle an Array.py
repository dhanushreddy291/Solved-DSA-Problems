class Solution:

    def __init__(self, nums: List[int]):
        self.origNums = nums
        self.N = len(nums)

    def reset(self) -> List[int]:
        return self.origNums

    def shuffle(self) -> List[int]:
        copyNums = self.origNums.copy()
        for i in range(self.N):
            randIndex = random.randint(0, self.N - 1)
            copyNums[i], copyNums[randIndex] = copyNums[randIndex], copyNums[i]
        return copyNums

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()