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
            if (board[i][0] == 'O') {
                board[i][0] = 'S';
                DFS(board, i, 0, X, Y);
            }
            if (board[i][Y - 1] == 'O') {
                board[i][Y - 1] = 'S';
                DFS(board, i, Y - 1, X, Y);
            }
        }
        for (int j = 1; j < Y - 1; j++) {
            if (board[0][j] == 'O') {
                board[0][j] = 'S';
                DFS(board, 0, j, X, Y);
            }
            if (board[X - 1][j] == 'O') {
                board[X - 1][j] = 'S';
                DFS(board, X - 1, j, X, Y);
            }
        }
    }
    private void DFS(char[][] board, int x, int y, int X, int Y) {
        for (int i = 0; i < 4; i++) {
            if (areValidCoordinates(x + dx[i], y + dy[i], X, Y)) {
                if (board[x + dx[i]][y + dy[i]] == 'O') {
                    board[x + dx[i]][y + dy[i]] = 'S';
                    DFS(board, x + dx[i], y + dy[i], X, Y);
                }
            }
        }
        return;
    }
    private boolean areValidCoordinates(int x, int y, int X, int Y) {
        return x >= 0 && x < X && y >= 0 && y < Y;
    }
    private char[][] rewriteTheBoard(char[][] board) {
        int X = board.length, Y = board[0].length;
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'S') board[i][j] = 'O';
            }
        }
        return board;
    }
}