class NumArray {
    private int[] PrefixSum;
    public NumArray(int[] nums) {
        int N = nums.length;
        PrefixSum = new int[N + 1];
        PrefixSum[0] = 0;
        for (int i = 0; i < N; i++) {
            PrefixSum[i + 1] = PrefixSum[i] + nums[i];
        }
    }
    
    public int sumRange(int left, int right) {
        return PrefixSum[right + 1] - PrefixSum[left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */