class Solution {
    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);
        if (k == 0) return new HashSet<>(Arrays.asList(nums)).size();
        int partitions = 0, Min = nums[0], Max = nums[0];
        for (int &num : nums) {
            Min = min(Min, num);
            Max = max(Max, num);
            if (Max - Min > k) {
                partitions++;
                Min = Max = num;
            }
        }
        return ++partitions;
    }
}