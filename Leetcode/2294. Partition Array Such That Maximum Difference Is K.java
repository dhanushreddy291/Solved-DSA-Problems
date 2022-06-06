class Solution {
    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);
        int partitions = 0, Min = nums[0], Max = nums[0];
        for (int num : nums) {
            Min = Math.min(Min, num);
            Max = Math.max(Max, num);
            if (Max - Min > k) {
                partitions++;
                Min = Max = num;
            }
        }
        return ++partitions;
    }
}