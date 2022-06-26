class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        i, j, currSum, maxSum = k - 1, len(cardPoints) - 1, sum(cardPoints[:k]), 0
        while i >= 0:
            maxSum = max(maxSum, currSum)
            currSum += (cardPoints[j] - cardPoints[i])
            j -= 1
            i -= 1
        return max(maxSum, currSum)