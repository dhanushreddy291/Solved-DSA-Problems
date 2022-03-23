class Solution:
    def brokenCalc(self, startValue: int, target: int) -> int:
        counter = 0
        while target > startValue:
            if target % 2 == 0: target /= 2
            else: target += 1
            counter += 1
        return (int)(counter + startValue - target)