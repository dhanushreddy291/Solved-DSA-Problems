class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:

        graph = [[] for i in range(n)]
        
        for i in range(len(manager)):
            if manager[i] != -1:
                graph[manager[i]].append(i)

        def DFS(node, currTime, graph, informTime):
            return max([
                DFS(subNode, currTime + informTime[node], graph, informTime) for subNode in graph[node]
            ]) if len(graph[node]) > 0 else currTime

        return DFS(headID, 0, graph, informTime)