class Solution {
private:
    vector <int> parent, size;
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    int Union(int x, int y) {
        int X = find(x), Y = find(y);
        if (X == Y) return 0;
        if (size[X] < size[Y]) {
            parent[X] = Y;
            size[Y] = max(size[Y], 1 + size[X]);
        } else {
            parent[Y] = X;
            size[X] = max(size[X], 1 + size[Y]);
        }
        return 1;
    }
    static bool cmp(vector <int> &log1, vector <int> &log2) {
        return log1[0] < log2[0];
    }
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), cmp);
        int components = n;
        parent = vector <int>(n);
        size = vector <int>(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (vector <int> &log: logs) {
            components -= Union(log[1], log[2]);
            if (components == 1) return log[0];
        }
        return -1;
    }
}; 