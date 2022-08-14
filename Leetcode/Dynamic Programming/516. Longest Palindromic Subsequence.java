class Solution {
    private int n;
    private int[][] DP;
    private int helper(int i, int j, String s) {
        if (i == n || j < 0) return 0;
        if (DP[i][j] != -1) return DP[i][j];
        if (s.charAt(i) == s.charAt(j)) return DP[i][j] = 1 + helper(i + 1, j - 1, s);
        return DP[i][j] = Math.max(helper(i + 1, j, s), helper(i, j - 1, s));
    }
    public int longestPalindromeSubseq(String s) {
        n = s.length();
        DP = new int[n][n];
        for (int[] row: DP) {
            Arrays.fill(row, -1);
        }
        return helper(0, n - 1, s);
    }
}