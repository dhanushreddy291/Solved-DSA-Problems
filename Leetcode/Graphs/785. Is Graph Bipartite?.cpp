class Solution {
private:
    bool DFS(int source, vector <int> &Color, vector<vector<int>>& graph, int color) {
        if (Color[source] == -1) {
            Color[source] = color;
            bool valid = true;
            int M = graph[source].size();
            for (int i = 0; i < M; i++) {
                if (!(DFS(graph[source][i], Color, graph, 1 - color))) {
                    valid = false;
                    break;
                }
            }
            return valid;
        } else return Color[source] == color;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        bool isGraphBipartite = true;
        vector <int> Color (N, -1);
        for (int i = 0; i < N; i++) {
            if (Color[i] == -1) {
                if (!(DFS(i, Color, graph, 1))) {
                    isGraphBipartite = false;
                    break;
                }
            }
        }
        return isGraphBipartite;
    }
};