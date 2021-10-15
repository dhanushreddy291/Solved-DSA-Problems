class Solution {
    public void sortColors(int[] nums) {
        int One = 0, Zero = 0, Two = 0, j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) One++;
            else if (nums[i] == 2) Two++;
            else Zero++;
        }
        while (Zero-- > 0) nums[j++] = 0;
        while (One-- > 0) nums[j++] = 1;
        while (Two-- > 0) nums[j++] = 2;
    }
}