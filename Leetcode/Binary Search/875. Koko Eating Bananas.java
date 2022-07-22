class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int lo = 1, hi = piles[0], N = piles.length, mid = 0;
        for (int i = 1; i < N; i++) {
            hi = Math.max(hi, piles[i]);
        }
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            long hours = 0;
            for (int i = 0; i < N; i++) {
                hours += (int) Math.ceil( (double)piles[i] / mid);
            }
            if (hours > Math.min(Integer.MAX_VALUE, (long)h)) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
}