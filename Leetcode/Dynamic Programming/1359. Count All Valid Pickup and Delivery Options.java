class Solution {
    public int countOrders(int n) {
        int prevOrders = 1, MOD = 1000000007;
        for (int i = 1; i <= n; i++) {
            long orders = (long)i * (long)((2 * i) - 1);
            orders %= MOD;
            orders *= prevOrders;
            orders %= MOD;
            prevOrders = (int)orders;
        }
        return prevOrders;
    }
}