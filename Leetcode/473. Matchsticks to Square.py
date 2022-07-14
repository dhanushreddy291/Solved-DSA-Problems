class Solution:
    
    def makesquare(self, matchsticks: List[int]) -> bool:

        def backtrack(i):
            if i == N:
                return min(sides) == max(sides)
            else:
                for j in range(4):
                    if sides[j] + matchsticks[i] <= sideLength:
                        sides[j] += matchsticks[i]
                        if backtrack(i + 1):
                            return True
                        sides[j] -= matchsticks[i]
                return False
        
        perimeter = sum(matchsticks)
        if perimeter % 4 != 0:
            return False
        matchsticks.sort(reverse=True)
        N = len(matchsticks)

        sides = [0, 0, 0, 0]
        sideLength = perimeter // 4
        return backtrack(0)
