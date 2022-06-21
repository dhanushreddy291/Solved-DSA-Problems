class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        Color = [-1 for i in range(len(graph))]

        def DFS(source, Color, graph, color):
            if Color[source] == -1:
                Color[source] = color
                M, valid = len(graph[source]), True
                for i in range(M):
                    if not DFS(graph[source][i], Color, graph, 1 - color):
                        return False
            return Color[source] == color

        for i in range(len(graph)):
            if Color[i] == -1:
                if not DFS(i, Color, graph, 1):
                    return False
        return True
