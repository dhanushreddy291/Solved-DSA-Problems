class Solution {
private:
    int N;
    vector <vector <vector <int>>> DP;
    bool valid(int x, int y) {
        return x < N && y < N;
    }
    int traverse(int x1, int y1, int x2, vector<vector<int>> &grid) {
        int y2 = x1 - x2 + y1;
        if (valid(x1, y1) && valid(x2, y2) && grid[x1][y1] != -1 && grid[x2][y2] != -1) {
            if (DP[x1][y1][x2] != -1) return DP[x1][y1][x2];
            if (x1 == N - 1 && x1 == y1) {
                return DP[x1][y1][x2] = grid[x1][y1];
            }
            int cherries = 0;
            if (x1 == x2 && y1 == y2) { cherries = grid[x1][y1]; } 
            else { cherries = grid[x1][y1] + grid[x2][y2]; }
            return DP[x1][y1][x2] = max(
                max(traverse(x1 + 1, y1, x2, grid), traverse(x1 + 1, y1, x2 + 1, grid)),
                max(traverse(x1, y1 + 1, x2, grid), traverse(x1, y1 + 1, x2 + 1, grid))
            ) + cherries;
        }
        return INT_MIN;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        N = grid.size();
        DP = vector <vector <vector <int>>> (N, vector <vector <int>> (N, vector <int> (N, -1)));
        return max(traverse(0, 0, 0, grid), 0);
    }
};