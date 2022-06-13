class Solution:
    def nextGreaterElement(self, n: int) -> int:
        Num = [int(i) for i in str(n)]
        for i in range(len(Num) - 2, -1, -1):
            if Num[i] < Num[i + 1]:
                Min = i + 1
                for j in range(i + 2, len(Num), 1):
                    if Num[j] > Num[i] and Num[Min] > Num[j]:
                        Min = j
                Num[i], Num[Min] = Num[Min], Num[i]
                Num[i+1:] = sorted(Num[i+1:])
                Ans = int("". join([str(i) for i in Num]))
                return -1 if Ans > (2**31) - 1 else Ans
        return -1