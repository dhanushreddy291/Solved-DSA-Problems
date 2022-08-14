class Solution {
private:
    vector <bool> Visited;
    vector <vector <int>> Graph;
    void DFS(int i) {
        if (!Visited[i]) {
            Visited[i] = true;
            for (int& neighbour: Graph[i]) {
                DFS(neighbour);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int connectedComponents = 0;
        Visited = vector <bool> (n, false);
        Graph = vector <vector <int>> (n);
        for (vector <int> &edge: edges) {
            Graph[edge[0]].push_back(edge[1]);
            Graph[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < n; i++) {
            if (!Visited[i]) {
                DFS(i);
                connectedComponents++;
            }
        }
        return connectedComponents;
    }
};


class Solution {
private:
    vector <int> parent, size;
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    int Union(int x, int y) {
        int X = find(x), Y = find(y);
        if (X == Y) return 0;
        if (size[X] < size[Y]) {
            parent[X] = Y;
            size[Y] = max(1 + size[X], size[Y]);
        } else {
            parent[Y] = X;
            size[X] = max(size[X], 1 + size[Y]);
        }
        return 1;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int components = n;
        parent = vector <int>(n);
        size = vector <int>(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (vector <int> &edge: edges) {
            components -= Union(edge[0], edge[1]);
        }
        return components;
    }
};