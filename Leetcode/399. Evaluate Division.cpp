class Solution {
private:
    double DFS(unordered_map <string, vector<pair <string, double>>> &Graph, string &Source, string &Target, double Answer, unordered_map <string, bool> &Visited) {
        if (Source == Target) return Answer;
        Visited[Source] = true;
        double Ans = -1.0;
        for (pair <string, double> &connection: Graph[Source]) {
            if (Visited[connection.first]) continue;
            Ans = DFS(Graph, connection.first, Target, Answer * connection.second, Visited);
            if (Ans != -1.0) break;
        }
        Visited[Source] = false;
        return Ans;
}
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map <string, bool> Visited;
        unordered_map <string, vector<pair <string, double>>> Graph;
        for (int i = 0; i < values.size(); i++) {
            Graph[equations[i][0]].push_back({equations[i][1], values[i]});
            Graph[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
            Visited[equations[i][0]] = false;
            Visited[equations[i][1]] = false;
        }
        vector <double> calcValues;
        for (vector <string>& query: queries) {
            if (Visited.find(query[0]) != Visited.end() && Visited.find(query[1]) != Visited.end()) {
                calcValues.push_back(DFS(Graph, query[0], query[1], 1.0, Visited));
            } else {
                calcValues.push_back(-1.0);
            }
        }
        return calcValues;
    }
};