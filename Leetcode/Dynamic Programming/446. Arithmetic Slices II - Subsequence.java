class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int N = nums.length, arithmeticSubSequences = 0;
        HashMap <Integer, Integer>[] Map = new HashMap[N];
        for (int i = 0; i < N; i++) {
            Map[i] = new HashMap<>();
        }
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                long d = (long)nums[i] - (long)nums[j];
                if (d > Integer.MIN_VALUE && d < Integer.MAX_VALUE) {
                    int apsEndingatJ = Map[j].getOrDefault((int)d, 0);
                    int apsEndingatI = Map[i].getOrDefault((int)d, 0);
                    Map[i].put((int)d, apsEndingatI + apsEndingatJ + 1);
                    arithmeticSubSequences += apsEndingatJ;
                }
            }
        }
        return arithmeticSubSequences;
    }
}