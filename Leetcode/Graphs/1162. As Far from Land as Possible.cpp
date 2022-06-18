class Solution {
private:
    bool isValidPosition(int x, int y, int X, int Y) {
        return x >= 0 && y >= 0 && x < X && y < Y;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size(), maxDist = 0;
        vector <int> dS = {-1, 1, 0, 0};
        vector <vector <bool>> Visited(N, vector <bool> (M, false));
        queue <pair <int, int>> Queue;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 1) {
                    Queue.push({i, j});
                    Visited[i][j] = true;
                    grid[i][j] = 0;
                } else grid[i][j] = 201;
            }
        }
        while (!Queue.empty()) {
            pair <int, int> Z = Queue.front();
            Queue.pop();
            for (int i = 0; i < 4; i++) {
                if (isValidPosition(Z.first + dS[i], Z.second + dS[3 - i], N, M)) {
                    if (!Visited[Z.first + dS[i]][Z.second + dS[3 - i]]) {
                        Visited[Z.first + dS[i]][Z.second + dS[3 - i]] = true;
                        Queue.push({Z.first + dS[i], Z.second + dS[3 - i]});
                        grid[Z.first + dS[i]][Z.second + dS[3 - i]] = min(grid[Z.first + dS[i]][Z.second + dS[3 - i]], 1 + grid[Z.first][Z.second]);
                    }
                }
            }
            maxDist = max(maxDist, grid[Z.first][Z.second]);
        }
        return maxDist == 0 ? -1 : maxDist;
    }
};