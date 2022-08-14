class Solution {
private:
    vector <int> parent, size;
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    bool Union(int x, int y) {
        int X = find(x), Y = find(y);
        if (X == Y) return false;
        if (size[X] < size[Y]) {
            parent[X] = Y;
            size[Y] = max(size[Y], 1 + size[X]);
        } else {
            parent[Y] = X;
            size[X] = max(size[X], 1 + size[Y]);
        }
        return true;
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        unordered_map <int, priority_queue <int, vector <int>, greater <int>>> Map;
        parent = vector <int>(n);
        size = vector <int>(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (vector <int> &pair: pairs) {
            Union(pair[0], pair[1]);
        }
        for (int i = 0; i < n; i++) {
            Map[find(i)].push(s[i]);
        }
        for (int i = 0; i < n; i++) {
            char Top = Map[parent[i]].top();
            Map[parent[i]].pop();
            s[i] = Top;
        }
        return s;
    }
};