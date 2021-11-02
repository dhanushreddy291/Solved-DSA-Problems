class Solution {
    private int[] dx = {-1, 1, 0, 0};
    private int[] dy = {0, 0, -1, 1};
    public int uniquePathsIII(int[][] grid) {
        int[] Start = {0, 0};
        int X = grid.length, Y = grid[0].length, zeroesCount = 0;
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                if (grid[i][j] == 0) zeroesCount++;
                else if (grid[i][j] == 1) {
                    Start[0] = i;
                    Start[1] = j;
                }
            }
        }
        return DFS(grid, Start[0], Start[1], X, Y, zeroesCount);
    }
    private int DFS(int[][] grid, int x, int y, int X, int Y, int zeroesCount) {
        if (grid[x][y] == -1) return 0;
        else if (grid[x][y] == 2) return zeroesCount == -1 ? 1 : 0;
        grid[x][y] = -1;
        int UniquePaths = 0;
        for (int i = 0; i < 4; i++) {
            if (ValidCoordinates(x + dx[i], y + dy[i], X, Y)) {
                UniquePaths += DFS(grid, x + dx[i], y + dy[i], X, Y, zeroesCount - 1);
            }
        }
        grid[x][y] = 0;
        return UniquePaths;
    } 
    private boolean ValidCoordinates(int x, int y, int X, int Y) {
        return x >= 0 && x < X && y >= 0 && y < Y;
    }
}