class Solution {
    public boolean divideArray(int[] nums) {
        int[] Freq = new int[501];
        for (int a : nums) {
            Freq[a]++;
        }
        for (int i = 0; i < 501; i++) {
            if (Freq[i] % 2 == 1) return false;
        }
        return true;
    }
}