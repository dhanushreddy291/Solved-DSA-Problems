class Solution {
    public int dominantIndex(int[] nums) {
        int FirstMax = Integer.MIN_VALUE, SecondMax = Integer.MIN_VALUE, N = nums.length, Answer = 0;
        for (int i = 0; i < N; i++) {
            if (nums[i] > FirstMax) {
                SecondMax = FirstMax;
                FirstMax = nums[i];
                Answer = i;
            }
            else if (nums[i] > SecondMax)
                SecondMax = nums[i];
        }
        return SecondMax * 2 > FirstMax ? -1 : Answer;
    }
}