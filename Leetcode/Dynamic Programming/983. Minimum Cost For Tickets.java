class Solution {
    private Map <Integer, Integer> DP = new HashMap<>();
    private int minCost(int[] days, int Start, int End, int[] costs) {
        if (Start >= End) return 0;
        else if (DP.containsKey(Start)) return DP.get(Start);
        else if (Start == End - 1) {
            DP.put(Start, Math.min(costs[0], Math.min(costs[1], costs[2])));
            return DP.get(Start);
        } else {
            int A = costs[0] + minCost(days, Start + 1, End, costs);
            int i = Start;
            while (i < End) {
                if (days[i] - days[Start] >= 7) break;
                else i++;
            }
            if (i == End) {
                DP.put(Start, Math.min(A, Math.min(costs[1], costs[2])));
                return DP.get(Start);
            }
            int B = costs[1] + minCost(days, i, End, costs);
            i = Start;
            while (i < End) {
                if (days[i] - days[Start] >= 30) break;
                else i++;
            }
            int C = costs[2] + minCost(days, i, End, costs);
            DP.put(Start, Math.min(A, Math.min(B, C)));
            return DP.get(Start);
        }
    }
    public int mincostTickets(int[] days, int[] costs) {
        return minCost(days, 0, days.length, costs);
    }
}