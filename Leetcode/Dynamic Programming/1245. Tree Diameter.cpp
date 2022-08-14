class Solution {
private:
    int diameter, n;
    vector <bool> Visited;
    vector <vector <int>> Graph;
    int DFS(int i) {
        if (Visited[i]) return INT_MIN;
        Visited[i] = true;
        int maxDiam = 0, secondmaxDiam = 0;
        for (int &child: Graph[i]) {
            int diam = DFS(child);
            if (diam >= maxDiam) {
                secondmaxDiam = maxDiam;
                maxDiam = diam;
            } else if (secondmaxDiam < diam) {
                secondmaxDiam = diam;
            }
        }
        diameter = max(diameter, maxDiam + secondmaxDiam);
        return 1 + maxDiam;
    }
public:
    int treeDiameter(vector<vector<int>>& edges) {
        n = edges.size() + 1;
        Graph = vector <vector <int>>(n);
        Visited = vector <bool> (n, false);
        for (vector <int> &edge: edges) {
            Graph[edge[0]].push_back(edge[1]);
            Graph[edge[1]].push_back(edge[0]);
        }
        diameter = 0;
        DFS(0);
        return diameter;
    }
};