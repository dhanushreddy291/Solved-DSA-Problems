class Solution {
    public int singleNumber(int[] nums) {
        int Answer = 0, size = nums.length;
        for (int i = 0; i < size; i++) Answer ^= nums[i];
        return Answer;
    }
}