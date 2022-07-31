class Solution {
    public int findPeakElement(int[] nums) {
        int N = nums.length;
        if (N == 1) return 0;
        if (N == 2) {
            return nums[0] > nums[1] ? 0 : 1;
        }
        int lo = 0, hi = N - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (mid < N - 1 && nums[mid] < nums[mid + 1]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
}