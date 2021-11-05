class Solution {
    public int maxIceCream(int[] costs, int coins) {
        int N = costs.length, i = 0, Sum = 0;
        Arrays.sort(costs);
        while (Sum < coins && i < N) {
            Sum += costs[i++];
        }
        if (Sum > coins) {
            if (Sum == costs[i - 1]) return 0;
            else return i - 1;
        } else return i;
    }
}