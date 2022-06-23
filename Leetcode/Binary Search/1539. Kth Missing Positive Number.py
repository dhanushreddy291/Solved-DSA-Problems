class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        maxNum = arr[-1]
        num = 1
        for i in range(maxNum):
            if not num in arr:
                k -= 1
            if k == 0: return num
            num += 1
        return maxNum + k