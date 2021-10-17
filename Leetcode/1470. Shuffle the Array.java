class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] Answer = new int[2*n];
        int i = 0, j = n, k = 0;
        while (k < 2*n) {
            Answer[k++] = nums[i++];
            Answer[k++] = nums[j++];
        }
        return Answer;
    }
}