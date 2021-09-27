class Solution {
public:
    bool isValidPos (int x, int y, int X, int Y) {
            return (x >= 0 && x < X && y >= 0 && y < Y);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue <pair <int, int>> RottenOranges;
        vector <int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        vector <vector <int>> Time (grid.size(), vector <int> (grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                        if (grid[i][j] == 2) RottenOranges.push ({i, j});
                }
        }
        while (!RottenOranges.empty()) {
                int X = RottenOranges.front().first, Y = RottenOranges.front().second;
                RottenOranges.pop();
                for (int i = 0; i < 4; i++) {
                        if (isValidPos (X + dx[i], Y + dy[i], grid.size(), grid[0].size())) {
                                if (grid[X + dx[i]][Y + dy[i]] == 1 && Time[X + dx[i]][Y + dy[i]] == 0) {
                                        RottenOranges.push ({X + dx[i], Y + dy[i]});
                                        Time[X + dx[i]][Y + dy[i]] = 1 + Time[X][Y];
                                        grid[X + dx[i]][Y + dy[i]] = 2;
                                }
                        }
                }
        }
        int TimeforRotting = 0;
        for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                        if (grid[i][j] == 1) return -1;
                        else TimeforRotting = max (TimeforRotting, Time[i][j]);
                }
        }
        return TimeforRotting;

    }
};