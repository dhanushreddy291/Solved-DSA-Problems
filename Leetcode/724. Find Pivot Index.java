class Solution {
    public int pivotIndex(int[] nums) {
        int N = nums.length;
        if (N == 1) return -1;
        int[] LeftSum = new int[N], RightSum = new int[N];
        LeftSum[0] = nums[0];
        RightSum[N - 1] = nums[N - 1];
        for (int i = 1; i < N; i++) {
            LeftSum[i] = LeftSum[i - 1] + nums[i];
            RightSum[N - i - 1] = RightSum[N - i] + nums[N - i - 1];
        }
        if (RightSum[1] == 0) return 0;
        for (int i = 1; i < N - 1; i++) {
            if (LeftSum[i - 1] == RightSum[i + 1]) return i;
        }
        if (LeftSum[N - 2] == 0) return N - 1;
        return -1;
    }
}