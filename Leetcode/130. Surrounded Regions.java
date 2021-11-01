class Solution {
    private int[] dx = {-1, 1, 0, 0};
    private int[] dy = {0, 0, -1, 1};
    public void solve(char[][] board) {
        checkAllTheEdges(board);
        rewriteTheBoard(board);
    }
    private void checkAllTheEdges(char[][] board) {
        int X = board.length, Y = board[0].length;
        for (int i = 0; i < X; i++) {
            if (board[i][0] == 'O') BFS(board, i, 0, X, Y);
            if (board[i][Y - 1] == 'O') BFS(board, i, Y - 1, X, Y);
        }
        for (int j = 1; j < Y - 1; j++) {
            if (board[0][j] == 'O') BFS(board, 0, j, X, Y);
            if (board[X - 1][j] == 'O') BFS(board, X - 1, j, X, Y);
        }
    }
    private void BFS(char[][] board, int x, int y, int X, int Y) {
        board[x][y] = 'S';
        for (int i = 0; i < 4; i++) {
            if (areValidCoordinates(x + dx[i], y + dy[i], X, Y) && board[x + dx[i]][y + dy[i]] == 'O') {
                BFS(board, x + dx[i], y + dy[i], X, Y);
            }
        }
    }
    private boolean areValidCoordinates(int x, int y, int X, int Y) {
        return x >= 0 && x < X && y >= 0 && y < Y;
    }
    private void rewriteTheBoard(char[][] board) {
        int X = board.length, Y = board[0].length;
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
}