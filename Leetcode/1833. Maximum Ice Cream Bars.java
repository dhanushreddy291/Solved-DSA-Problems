class Solution {
    public int maxIceCream(int[] costs, int coins) {
        int N = costs.length, i = 0, Sum = 0;
        Arrays.sort(costs);
        while (Sum < coins && i < N) {
            Sum += costs[i++];
        }
        if (Sum > coins) {
            Sum -= costs[i - 1];
            if (Sum == 0) return 0;
            return i - 1;
        }
        return i;
    }
}