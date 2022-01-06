class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        N = len(trips)
        PrefixSum = [0] * 1001
        for i in range(N):
            if trips[i][0] > capacity: 
                return False
            PrefixSum[trips[i][1]] += trips[i][0]
            PrefixSum[trips[i][2]] -= trips[i][0]
        for i in range(1001):
            PrefixSum[i] += PrefixSum[i - 1]
            if PrefixSum[i] > capacity:
                 return False
        return True