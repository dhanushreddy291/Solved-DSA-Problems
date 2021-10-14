class Solution {
public:
    void DFS (int Start, vector<vector<int>>& isConnected, vector<bool>& Visited, int N) {
        for (int i = 0; i < N; i++) {
            if (isConnected[Start][i] && !Visited[i]) {
                Visited[i] = true;
                DFS (i, isConnected, Visited, N);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected[0].size(), NumberofProvinces = 0;
        vector <bool> Visited (N, false);
        for (int i = 0; i < N; i++) {
            if (!Visited[i]) {
                Visited[i] = true;
                DFS (i, isConnected, Visited, N);
                NumberofProvinces++;
            }
        }
        return NumberofProvinces;
    }
};