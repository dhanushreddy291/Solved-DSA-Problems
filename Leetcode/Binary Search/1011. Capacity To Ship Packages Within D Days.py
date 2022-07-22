class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        lo, hi, N = max(weights), sum(weights), len(weights)
        while lo <= hi:
            mid = (lo + hi) // 2
            i, days, Sum = 0, 0, 0
            while days < D and i < N:
                if Sum + weights[i] == mid:
                    Sum = 0
                    days += 1
                elif Sum + weights[i] > mid:
                    Sum = weights[i]
                    days += 1
                else:
                    Sum += weights[i]
                i += 1
            print(lo, mid, hi, days, i, Sum)
            if i < N:
                lo = mid + 1
            else:
                hi = mid - 1
        return lo
