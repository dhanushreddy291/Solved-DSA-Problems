class Solution {
    public int maximumWealth(int[][] accounts) {
        int m = accounts.length, n = accounts[0].length, Answer = 0;
        for (int i = 0; i < m; i++) {
            int Sum = 0;
            for (int j = 0; j < n; j++) Sum += accounts[i][j];
            Answer = Math.max(Sum, Answer);
        }
        return Answer;
    }
}