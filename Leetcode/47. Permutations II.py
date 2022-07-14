class Solution:
    
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        self.permutations = []
        self.currPermutation = []
        self.Map = {}
        for num in nums:
            if num in self.Map:
                self.Map[num] += 1
            else:
                self.Map[num] = 1
        self.findPermutations(0, len(nums))
        return self.permutations

    def findPermutations(self, i, N):

        if i == N:
            self.permutations.append(self.currPermutation.copy())

        else:
            for num in self.Map:
                if self.Map[num] > 0:
                    self.currPermutation.append(num)
                    self.Map[num] -= 1
                    self.findPermutations(i + 1, N)
                    self.Map[num] += 1
                    self.currPermutation.pop()
