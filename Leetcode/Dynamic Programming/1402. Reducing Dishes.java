class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int[][] Map = new int[501][501];
        for (int i = 0; i < 501; i++) {
            for (int j = 0; j < 501; j++) 
                Map[i][j] = -1;
        }
        return FindMax(satisfaction, 0, satisfaction.length, 1, Map);
    }
    private int FindMax(int[] satisfaction, int Start, int End, int Val, int[][] Map) {
        if (Start >= End) return 0;
        else if (Map[Start][Val] != -1) return Map[Start][Val];
        else if (satisfaction[Start] >= 0) {
            int Satisfaction = 0;
            for (int i = Start; i < End; i++, Val++) {
                Satisfaction += (Val * satisfaction[i]);
            }
            return Map[Start][Val] = Satisfaction;
        }
        else return Map[Start][Val] = Math.max(satisfaction[Start] * Val + FindMax(satisfaction, Start + 1, End, Val + 1, Map), FindMax(satisfaction, Start + 1, End, Val, Map));
    }
}