class Solution {
public:
    bool isValidPos (int x, int y, int X, int Y) {
        return (x < X && y < Y && x >= 0 && y >= 0);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue <pair <int, int>> Queue;
        vector <int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        vector <vector <int>> Distance (mat.size(), vector <int> (mat[0].size(), 0));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) { 
                if (mat[i][j] == 0) 
                    Queue.push ({i, j});
            }
        }
        while (!Queue.empty()) {
            int X = Queue.front().first, Y = Queue.front().second;
            for (int i = 0; i < 4; i++) {
                if (isValidPos (X + dx[i], Y + dy[i], mat.size(), mat[0].size())) {
                    if (mat[X + dx[i]][Y + dy[i]] == 1 && Distance[X + dx[i]][Y + dy[i]] == 0) {
                        Distance[X + dx[i]][Y + dy[i]] = Distance[X][Y] + 1;
                        Queue.push ({X + dx[i], Y + dy[i]});
                    }
                }
            }
            Queue.pop();
        }
        return Distance;      
    }
};