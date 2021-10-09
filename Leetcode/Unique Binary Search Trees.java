class Solution {
    public int numTrees(int n) {
        //Answer is the nth Catalan Number
        int Catalan[] = new int[n + 2];
        Catalan[0] = Catalan[1] = 1;
        for (int i = 2; i <= n; i++) {
            Catalan[i] = 0;
            for (int j = 0; j < i; j++) 
                Catalan[i] += Catalan[j] * Catalan[i - j - 1];
        }
        return Catalan[n];
    }
}