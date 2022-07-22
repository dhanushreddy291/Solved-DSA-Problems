class Solution {
private:
    bool diagCheck(vector <string> &board, int x, int y, int n) {
        int i = x - 1, j = y - 1;
        while (i >= 0 && j >= 0) {
            if (board[i--][j--] == 'Q') return false;
        }
        while (x > 0 && y < n - 1) {
            if (board[--x][++y] == 'Q') return false;
        }
        return true;
    }
    void helper(int i, int n, vector <string> &currBoard, vector <vector <string>> &possibleBoards, vector <int> &Col) {
        if (i == n) {
            possibleBoards.push_back(currBoard);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!Col[j] && diagCheck(currBoard, i, j, n)) {
                currBoard[i][j] = 'Q';
                Col[j] = true;
                helper(i + 1, n, currBoard, possibleBoards, Col);
                Col[j] = false;
                currBoard[i][j] = '.';
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector <int> Col(n, false);
        string base = "";
        for (int i = 0; i < n; i++) {
            base += '.';
        }
        vector <string> currBoard(n, base);
        vector <vector <string>> possibleBoards;
        helper(0, n, currBoard, possibleBoards, Col);
        return possibleBoards;
    }
};