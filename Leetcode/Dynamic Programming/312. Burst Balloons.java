class Solution {
    private int[][] DP;
    private int N;
    private int helper(int L, int R, int[] nums) {
        if (L > R) return 0;
        if (DP[L][R] != -1) return DP[L][R];
        for (int i = L; i <= R; i++) {
            DP[L][R] = Math.max(DP[L][R], helper(L, i - 1, nums) + helper(i + 1, R, nums) + nums[i] * ((L > 0) ? nums[L - 1] : 1) * ((R + 1 < N) ? nums[R + 1] : 1));
        }
        return DP[L][R];
    }
    public int maxCoins(int[] nums) {
        N = nums.length;
        DP = new int[N][N];
        for (int[] row: DP) {
            Arrays.fill(row, -1);
        }
        return helper(0, N - 1, nums);
    }
}