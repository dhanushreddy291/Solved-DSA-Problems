class Solution {
    public int countTriples(int n) {
        int Count = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int c = a * a + b * b;
                int sqrtC = (int)Math.sqrt(c);
                if (sqrtC * sqrtC == c && sqrtC <= n) Count++;
            }
        }
        return Count;
    }
}