class Solution {
    private int maxScore = 0;
    private int score(int[] aliceArrows, int[] bobArrows) {
        int Score = 0;
        for (int i = 0; i < 12; i++) {
            if (aliceArrows[i] < bobArrows[i]) Score += i;
        }
        return Score;
    }
    private void helper(int numArrows, int[] aliceArrows, int[] bobArrows, int position, int[] answerArrows) {
        if (numArrows == 0 || position == 0) {
            int currentScore = score(aliceArrows, bobArrows);
            if (currentScore > maxScore) {
                maxScore = currentScore;
                for (int i = 0; i < 12; i++) {
                    answerArrows[i] = bobArrows[i];
                }
                answerArrows[0] = numArrows;
            }
        } else if (position >= 0 && numArrows > 0) {
            if (numArrows > aliceArrows[position]) {
                bobArrows[position] = aliceArrows[position] + 1;
                helper(numArrows - bobArrows[position], aliceArrows, bobArrows, position - 1, answerArrows);
                bobArrows[position] = 0;
            }
            helper(numArrows, aliceArrows, bobArrows, position - 1, answerArrows);
        }
        return;
    }
    public int[] maximumBobPoints(int numArrows, int[] aliceArrows) {
        int[] bobArrows = new int[12], answerArrows = new int[12];
        int maxScore = 0;
        helper(numArrows, aliceArrows, bobArrows, 11, answerArrows);
        return answerArrows;
    }
}