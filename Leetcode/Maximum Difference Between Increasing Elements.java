class Solution {
    public int maximumDifference(int[] nums) {
        int MaxDiff = -1, MinNum = nums[0], i = 1;
            while (i < nums.length) {
                if (nums[i] > MinNum)
                    MaxDiff = Math.max(MaxDiff, nums[i] - MinNum);
                MinNum = Math.min(MinNum, nums[i++]);
        }
        return MaxDiff;
    }
}