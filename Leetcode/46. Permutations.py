class Solution:

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.indexes = [0] * len(nums)
        self.permutations = []
        self.currPermutation = []
        self.findPermutations(0, len(nums), nums)
        return self.permutations

    def findPermutations(self, i, N, nums):

        if i == N:
            self.permutations.append(self.currPermutation.copy())

        else:
            for j in range(N):
                if self.indexes[j] == 0:
                    self.currPermutation.append(nums[j])
                    self.indexes[j] = 1
                    self.findPermutations(i + 1, N, nums)
                    self.indexes[j] = 0
                    self.currPermutation.pop()
