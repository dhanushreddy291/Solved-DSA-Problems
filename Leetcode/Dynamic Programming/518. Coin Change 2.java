class Solution {
    public int change(int amount, int[] coins) {
        int[] DP = new int[amount + 1];
        Arrays.fill(DP, 0);
        DP[0] = 1;
        for (int i = 0; i < coins.length; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                DP[j] += DP[j - coins[i]];
            }
        }
        return DP[amount];
    }
}