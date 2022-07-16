class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        i, N = 0, len(s)
        maxLength = max([len(word) for word in wordDict])
        DP = [-1] * N
        def helper(i):
            if i == N:
                return True
            if DP[i] != -1:
                return DP[i] > 0
            currStr = ""
            while i < N:
                if len(currStr) > maxLength:
                    DP[i] = 0
                    return False
                currStr += s[i]
                i += 1
                if currStr in wordDict:
                    if helper(i):
                        return True
            DP[i] = 0
            return False
        
        return helper(0)
