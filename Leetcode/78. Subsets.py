class Solution:
    
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.allSubsets = []
        self.currSubset = []
        self.findSubsets(0, len(nums), nums)
        return self.allSubsets
    
    def findSubsets(self, i, N, nums):

        if i == N:
            self.allSubsets.append(self.currSubset.copy())
        
        elif i < N:
            self.currSubset.append(nums[i])
            self.findSubsets(i + 1, N, nums)
            self.currSubset.pop()
            self.findSubsets(i + 1, N, nums)
