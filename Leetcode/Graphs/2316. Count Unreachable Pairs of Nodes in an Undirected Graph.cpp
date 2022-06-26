class Solution {
private:
    long long DFS(vector <vector <int>> &Graph, vector <bool> &Visited, int source) {
        if (Visited[source]) return 0;
        else {
            Visited[source] = true;
            int N = Graph[source].size();
            long long count = 0;
            for (int i = 0; i < N; i++) {
                count += DFS(Graph, Visited, Graph[source][i]);
            }
            return 1 + count;
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector <vector <int>> Graph(n);
        int N = edges.size();
        long long connected = 0;
        for (int i = 0; i < N; i++) {
            Graph[edges[i][0]].push_back(edges[i][1]);
            Graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector <bool> Visited (n, false);
        for (int i = 0; i < n; i++) {
            long long t = DFS(Graph, Visited, i);
            t *= (t - 1);
            t /= 2;
            connected += t;
        }
        long long total = n;
        total *= (total - 1);
        total /= 2;
        return total - connected;
    }
};