class Solution {
    private int[] isANumber(String s, int i) {
        if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
            int N = (s.charAt(i) - '0');
            if (i + 1 < s.length()) {
                int[] k = isANumber(s, i + 1);
                if (k[0] == -1) return new int[]{N, 2};
                else {
                    if (k[0] / 10 == 0) return new int[]{10 * N + k[0], 3};
                    else return new int[]{100 * N + k[0], 4};
                }
            }
            else return new int[]{N, 1};
        }
        return new int[]{-1, 1};
    }
    public boolean areNumbersAscending(String s) {
        int N = s.length(), i = 0, PreviousNum = 0;
        while (i < N) {
            int[] k = isANumber(s, i);
            if (k[0] != -1) {
                if (PreviousNum >= k[0]) return false;
                else PreviousNum = k[0];
            }
            i += k[1];
        }
        return true;
    }
}