class Solution:
    def candy(self, ratings: List[int]) -> int:
        N = len(ratings)
        candies = [1] * N
        for i in range(1, N):
            if ratings[i] > ratings[i - 1]:
                candies[i] = 1 + candies[i - 1]
        for i in range(N - 2, -1, -1):
            if ratings[i] > ratings[i + 1] and candies[i] <= candies[i + 1]:
                candies[i] = 1 + candies[i + 1]
        return sum(candies)
