class Solution {
private:
    vector <bool> Visited;
    bool DFS(int node, int parent, vector <vector <int>> &Graph) {
        if (Visited[node]) return false;
        Visited[node] = true;
        for (int &neighbour: Graph[node]) {
            if (neighbour != parent) {
                if (!DFS(neighbour, node, Graph)) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector <vector <int>> Graph(n);
        for (vector <int> &edge: edges) {
            Graph[edge[0]].push_back(edge[1]);
            Graph[edge[1]].push_back(edge[0]);
        }
        Visited = vector <bool> (n, false);
        if (!DFS(0, -1, Graph)) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!Visited[i]) {
                return false;
            }
        }
        return true;
    }
};



// Using Union Find
class Solution {
private:
    vector <int> parent;
    int find(int x) {
        while (x != parent[x]) {
            x = parent[x];
        }
        return x;
    }
    int union(int x, int y) {
        int X = find(x);
        int Y = find(y);
        if (X == Y) return false;
        parent[X] = Y;
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        parent = vector <int> (n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (vector <int> &edge: edges) {
            if (!union(edge[0], edge[1])) {
                return false;
            }
        }
        return true;
    }
};


// Using Path Compression in Union Find
class Solution {
private:
    vector <int> parent;
    int find(int x) {
        while (x != parent[x]) {
            x = parent[x];
        }
        return x;
    }
    bool Union(int x, int y) {
        int X = find(x);
        int Y = find(y);
        if (X == Y) return false;
        parent[X] = Y;
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        parent = vector <int> (n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (vector <int> &edge: edges) {
            if (!Union(edge[0], edge[1])) {
                return false;
            }
        }
        return true;
    }
};

// Link to the Blog Post: https://leetcode.com/problems/graph-valid-tree/discuss/2414179

class Solution {
private:
    vector <int> parent, size;
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool Union(int x, int y) {
        int X = find(x);
        int Y = find(y);
        if (X == Y) return false;
        if (size[X] < size[Y]) {
            parent[X] = Y;
            size[Y] = max(size[Y], 1 + size[X]);
        } else {
            parent[Y] = X;
            size[X] = max(1 + size[Y], size[X]);
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        parent = vector <int> (n);
        size = vector <int> (n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        for (vector <int> &edge: edges) {
            if (!Union(edge[0], edge[1])) {
                return false;
            }
        }
        return true;
    }
};