class Solution {
public:
    vector <vector <int>> Answer;
    vector <int> Path;
    void GetAllPaths (vector<vector<int>>& graph, int Source, int Destination) {
        if (Source == Destination) Answer.push_back (Path);
        else {
            int N = graph[Source].size();
            for (int i = 0; i < N; i++) {
                Path.push_back (graph[Source][i]);
                GetAllPaths (graph, graph[Source][i], Destination);
                Path.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int N = graph.size();
        Path.push_back (0);
        GetAllPaths (graph, 0, N - 1);
        return Answer;
    }
};