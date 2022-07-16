class Solution {
    public int minNumberOperations(int[] target) {
        int count = target[0], N = target.length;
        for (int i = 1; i < N; i++) {
            if (target[i] > target[i - 1]) {
                count += target[i] - target[i - 1];
            }
        }
        return count;
    }
}