class Solution {
    private int allPaths(int x, int y, int X, int Y, int moves, int[][][] paths, int[] ds) {
        if (x < 0 || y < 0 || x >= X || y >= Y) return 1;
        if (moves <= 0) return 0;
        if (paths[x][y][moves] == -1) {
            long ways = 0;
            for (int i = 0; i < 4; i++) {
                ways += allPaths(x + ds[i], y + ds[3 - i], X, Y, moves - 1, paths, ds);
                ways %= 1000000007;
            }
            paths[x][y][moves] = (int)ways;
        }
        return paths[x][y][moves];
    }
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int[][][] paths = new int[m][n][maxMove + 1];
        int[] ds = {-1, 1, 0, 0};
        for (int[][] matrix: paths) {
            for (int[] row: matrix) {
                Arrays.fill(row, -1);
            }
        }
        return allPaths(startRow, startColumn, m, n, maxMove, paths, ds) % 1000000007;
    }
}