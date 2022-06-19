class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:

        provinces = 0
        N = len(isConnected)
        Visited = [False for x in range(N)]
        graph = [[] for x in range(N)]

        for i in range(N):
            for j in range(N):
                if isConnected[i][j]:
                    graph[i].append(j)
                    graph[j].append(i)

        def DFS(node, graph, Visited):
            for subNode in graph[node]:
                if not Visited[subNode]:
                    Visited[subNode] = True
                    DFS(subNode, graph, Visited)

        for i in range(N):
            if not Visited[i]:
                Visited[i] = True
                DFS(i, graph, Visited)
                provinces += 1
        
        return provinces