class Solution {
private:
    bool isValidPos(int x, int y, int N, int M) {
        return x >= 0 && y >= 0 && x < N && y < M;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue <pair <int, int>> Queue;
        Queue.push({sr, sc});
        vector <int> ds = {1, -1, 0, 0};
        int N = image.size(), M = image[0].size();
        vector <vector <bool>> Visited(N, vector <bool> (M, false));
        Visited[sr][sc] = true;
        while (!Queue.empty()) {
            pair <int, int> Pos = Queue.front();
            Queue.pop();
            for (int i = 0; i < 4; i++) {
                int x = Pos.first + ds[i], y = Pos.second + ds[3 - i];
                if (isValidPos(x, y, N, M) && !Visited[x][y] && image[x][y] == image[sr][sc]) {
                    Queue.push({x, y});
                    image[x][y] = color;
                    Visited[x][y] = true;
                }
            }
        }
        image[sr][sc] = color;
        return image;
    }
};