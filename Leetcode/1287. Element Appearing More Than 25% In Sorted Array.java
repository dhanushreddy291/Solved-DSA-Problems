class Solution {
    public int findSpecialInteger(int[] arr) {
        int N = arr.length, M = N/4;
        for (int i = 0; i < N - M; i++) {
            if (arr[i] == arr[i + M])
                return arr[i];
        }
        // Answer always exists as per given conditions so wont come till here
        throw new RuntimeException("Invalid Input");
    }
}