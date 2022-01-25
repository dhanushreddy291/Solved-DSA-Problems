class Solution {
    public boolean validMountainArray(int[] arr) {
        int N = arr.length, i = 0;
        boolean isStrictlyIncreasing = false, isStrictlyDecreasing = false;
        if (N > 2) {
            while (i < N - 1 && arr[i] < arr[i + 1]) {
                i++;
                isStrictlyIncreasing = true;
            }
            if (i < N - 1 && arr[i] == arr[i + 1]) return false;
            while (i < N - 1 && arr[i] > arr[i + 1]) {
                i++;
                isStrictlyDecreasing = true;
            }
        }
        return N > 2 && i == N - 1 && isStrictlyIncreasing && isStrictlyDecreasing;
    }
}