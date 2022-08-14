class Solution {
    private int[][][] DP;
    private int helper(int i, int j, String s, char prev) {
        if (i >= j) return 0;
        if (DP[i][j][prev - 'a'] != -1) return DP[i][j][prev - 'a'];
        if (s.charAt(i) != prev && s.charAt(i) == s.charAt(j)) {
            return DP[i][j][prev - 'a'] = 2 + helper(i + 1, j - 1, s, s.charAt(i));
        }
        return DP[i][j][prev - 'a'] = Math.max(helper(i + 1, j, s, prev), helper(i, j - 1, s, prev));
    }
    public int longestPalindromeSubseq(String s) {
        DP = new int[s.length()][s.length()][27];
        for (int[][] matrix: DP) {
            for (int[] row: matrix) {
                Arrays.fill(row, -1);
            }
        }
        return helper(0, s.length() - 1, s, (char)('z' + 1));
    }
}