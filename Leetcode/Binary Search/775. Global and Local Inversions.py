class Solution:
    def isIdealPermutation(self, nums: List[int]) -> bool:
        N = len(nums)
        localInversions = 0
        self.globalInversions = 0
        for i in range(N - 1):
            if nums[i] > nums[i + 1]:
                localInversions += 1
        self.mergeSort(nums, 0, N - 1)
    
    def mergeSort(self, nums, start, end):
        if start <= end:
            mid = (start + end) // 2
            self.mergeSort(nums, start, mid)
            self.mergeSort(nums, mid + 1, end)
            self.merge(nums, start, mid, mid + 1, end)
    
    def merge(self, nums, start1, end1, start2, end2):
        while start1 <= end1 and start2 <= end2:
            if nums[start1]

