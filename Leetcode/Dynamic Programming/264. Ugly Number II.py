class Solution:
    def nthUglyNumber(self, n: int) -> int:
        DP = [1]
        Ptr1 = Ptr2 = Ptr3 = 0
        for i in range(1, n, 1):
            Fac1 = DP[Ptr1] * 2
            Fac2 = DP[Ptr2] * 3
            Fac3 = DP[Ptr3] * 5
            Min = min(Fac1, Fac2, Fac3)
            if Fac1 == Min: Ptr1 += 1
            if Fac2 == Min: Ptr2 += 1
            if Fac3 == Min: Ptr3 += 1
            DP.append(Min)
        return DP[n - 1]