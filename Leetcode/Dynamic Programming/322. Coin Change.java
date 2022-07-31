class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] minCoinsRequired = new int[amount + 1];
        minCoinsRequired[0] = 0;
        for (int i = 1; i <= amount; i++) {
            minCoinsRequired[i] = amount + 1;
            for (int j = 0; j < coins.length; j++) {
                if (i >= coins[j]) {
                    minCoinsRequired[i] = Math.min(minCoinsRequired[i], 1 + minCoinsRequired[i - coins[j]]);
                }
            }
        }
        return minCoinsRequired[amount] > amount ? -1: minCoinsRequired[amount];
    }
}