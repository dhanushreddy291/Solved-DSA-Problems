class Solution {
public:
    bool isValidPos (int x, int y, int X, int Y) {
        return (x >= 0 && y >= 0 && x < X && y < Y);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int SR, int SC, int newColor) {
        vector <vector <bool>> Visited (image.size(), vector <bool> (image[0].size(), false));
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
                        image[sr + dx[i]][sc + dy[i]] = newColor;
                    }
            Queue.pop();
        }
        image[SR][SC] = newColor;
        return image;
    }
};