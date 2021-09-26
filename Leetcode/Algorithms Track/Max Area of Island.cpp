class Solution {
public:
    bool isValidPos (int x, int y, int X, int Y) {
        return (x >= 0 && y >= 0 && x < X && y < Y);
    }
    int Fill(vector<vector<int>>& image, int SR, int SC, vector <vector <bool>> &Visited) {
        int Count = 0;
        queue <pair <int, int>> Queue;
        Queue.push({SR, SC});
        vector <int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        Visited[SR][SC] = true;
        while (!Queue.empty()) {
            int sr = Queue.front().first, sc = Queue.front().second;
            for (int i = 0; i < 4; i++)
                if (isValidPos (sr + dx[i], sc + dy[i], image.size(), image[0].size()))
                    if (!Visited[sr + dx[i]][sc + dy[i]]) 
                    if (image[SR][SC] == image[sr + dx[i]][sc + dy[i]]) {
                        Visited[sr + dx[i]][sc + dy[i]] = true;
                        Queue.push ({sr + dx[i], sc + dy[i]});
                        image[sr + dx[i]][sc + dy[i]] = 0;
                        Count++;
                    }
            Queue.pop();
        }
        image[SR][SC] = 0;
        return 1 + Count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int MaxArea = 0;
        vector <vector <bool>> Visited (grid.size(), vector <bool> (grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1)
                    MaxArea = max (MaxArea, Fill (grid, i, j, Visited));
        return MaxArea;
    }
};