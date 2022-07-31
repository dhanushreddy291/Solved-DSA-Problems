class Solution {
    int[] nums;
    int N;
    boolean useRandom;
    Map<Integer, Integer> map;
    public Solution(int n, int[] blacklist) {
        if (n > 20000 && n/2 > blacklist.length) {
            N = n;
            useRandom = true;
            map = new HashMap();
            for (int b : blacklist) {
                map.put(b, -1);
            }
        } else {
            useRandom = false;
            int j = 0, k = 0, m = blacklist.length;
            nums = new int[n - m];
            Arrays.sort(blacklist);
            for (int i = 0; i < n; i++) {
                if (j < m && blacklist[j] == i) j++;
                else nums[k++] = i;
            }
        }
    }
    
    public int pick() {
        if (!useRandom) return nums[(int)(Math.random() * nums.length)];
        int k = (int)(Math.random() * N);
        while (map.containsKey(k)) {
            k = (int)(Math.random() * N);
        }
        return k;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n, blacklist);
 * int param_1 = obj.pick();
 */