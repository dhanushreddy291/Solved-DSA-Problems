class Solution {
private:

    int findGrid(int i, int j) {
        return (i / 3) * 3 + (j/3);
    }

    bool helper(vector<vector<char>> &board, int i, int j, vector <vector <bool>> &Row, vector <vector <bool>> &Column, vector <vector <bool>> &Grid) {

        if (j == 9) return helper(board, i + 1, 0, Row, Column, Grid);
        if (i == 9) return true;
        if (board[i][j] != '.') return helper(board, i, j + 1, Row, Column, Grid);

        for (int k = 0; k < 9; k++) {

            int gridId = findGrid(i, j), num = k;

            if (Row[i][num] || Column[j][num] || Grid[gridId][num]) continue;
            
            board[i][j] = ('1' + num);
            Row[i][num] = Column[j][num] = Grid[gridId][num] = true;

            if (helper(board, i, j + 1, Row, Column, Grid)) return true;

            Row[i][num] = Column[j][num] = Grid[gridId][num] = false;
            board[i][j] = '.';

        }

        return false;

    }

public:
    void solveSudoku(vector<vector<char>>& board) {

        vector <bool> temp(9, false);
        vector <vector <bool>> Row(9, temp), Column(9, temp), Grid(9, temp);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int gridId = findGrid(i, j), num = (board[i][j] - '1');
                    Row[i][num] = Column[j][num] = Grid[gridId][num] = true;
                }
            }
        }

        helper(board, 0, 0, Row, Column, Grid);
        
    }
};