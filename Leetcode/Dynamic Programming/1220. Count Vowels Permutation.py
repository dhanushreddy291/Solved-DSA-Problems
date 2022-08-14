class Solution:
    def countVowelPermutation(self, n: int) -> int:
        ways = [1] * 5
        for i in range(n - 1):
            ways = [
                ways[1] + ways[2] + ways[4],
                ways[0] + ways[2],
                ways[1] + ways[3],
                ways[2],
                ways[2] + ways[3]
            ]
            ways = [way % (10 ** 9 + 7) for way in ways]
        return sum(ways) % (10 ** 9 + 7)