class Solution {
    public int[] productExceptSelf(int[] nums) {
        int N = nums.length, zerExcProduct = 1, Product = 1, zeroes = 0;
        for (int i = 0; i < N; i++) {
            if (nums[i] != 0) zerExcProduct *= nums[i];
            else zeroes++;
            Product *= nums[i];
        }
        if (zeroes > 1) return new int[N];
        for (int i = 0; i < N; i++) {
            if (nums[i] == 0) nums[i] = zerExcProduct;
            else nums[i] = Product/nums[i];
        }
        return nums;
    }
}