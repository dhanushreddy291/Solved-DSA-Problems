class Solution {
private:
    vector <int> ds = {-1, 1, 0, 0};
    bool helper(vector<vector<char>>& board, int i, int j, string word) {
        if (word.size() == 0) return true;
        if (board[i][j] != word[0]) return false;
        if (board[i][j] == word[0]) {
            char ch = board[i][j];
            board[i][j] = '0';
            word = word.substr(1, word.size() - 1);
            for (int k = 0; k < 4; k++) {
                int x = i + ds[k], y = j + ds[3 - k];
                if (x >= 0 && x < board.size() && y < board[0].size() && y >= 0) {
                    if (board[x][y] == word[0] && helper(board, x, y, word)) return true;
                }
            }
            board[i][j] = ch;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) return true;
        int N = board.size(), M = board[0].size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (helper(board, i, j, word)) return true;
            }
        }
        return false;
    }
};