class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        Indegree, Outdegree, Max = [0] * n, [0] * n, 0
        for edge in trust:
            Outdegree[edge[0] - 1] += 1
            Indegree[edge[1] - 1] += 1
            if Indegree[edge[1] - 1] > Indegree[Max]:
                Max = edge[1] - 1
        return Max + 1 if Outdegree[Max] == 0 and Indegree[Max] == n - 1 else -1